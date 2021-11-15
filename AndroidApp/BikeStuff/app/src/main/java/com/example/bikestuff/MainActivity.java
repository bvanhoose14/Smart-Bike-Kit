package com.example.bikestuff;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.ActionBar;
import android.app.Activity;
import android.content.Intent;
import android.location.Location;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import com.harrysoft.androidbluetoothserial.BluetoothManager;
import com.harrysoft.androidbluetoothserial.BluetoothSerialDevice;
import com.harrysoft.androidbluetoothserial.SimpleBluetoothDeviceInterface;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
//import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothSocket;
import com.mapbox.android.core.location.LocationEngine;
import com.mapbox.android.core.location.LocationEngineCallback;
import com.mapbox.android.core.location.LocationEngineProvider;
import com.mapbox.android.core.location.LocationEngineRequest;
import com.mapbox.android.core.location.LocationEngineResult;
import com.mapbox.android.core.permissions.PermissionsListener;
import com.mapbox.android.core.permissions.PermissionsManager;
import com.mapbox.mapboxsdk.Mapbox;
import com.mapbox.mapboxsdk.location.LocationComponent;
import com.mapbox.mapboxsdk.location.LocationComponentActivationOptions;
import com.mapbox.mapboxsdk.location.modes.CameraMode;
import com.mapbox.mapboxsdk.location.modes.RenderMode;
import com.mapbox.mapboxsdk.maps.MapView;
import com.mapbox.mapboxsdk.maps.MapboxMap;
import com.mapbox.mapboxsdk.maps.OnMapReadyCallback;
import com.mapbox.mapboxsdk.maps.Style;

import java.io.InputStream;
import java.io.OutputStream;
import java.lang.ref.WeakReference;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

import io.reactivex.android.schedulers.AndroidSchedulers;
import io.reactivex.schedulers.Schedulers;

public class MainActivity extends AppCompatActivity implements
        OnMapReadyCallback, PermissionsListener {

    private SimpleBluetoothDeviceInterface deviceInterface;
    BluetoothManager bluetoothManager = BluetoothManager.getInstance();
    BluetoothDevice mcu;
    private byte LEFT = 0;
    private byte RIGHT = 0;
    private OutputStream outputStream;
    private InputStream inStream;
    private boolean readspeed = false;
    private int wheelsize;
    private PermissionsManager permissionsManager;
    private MapView mapView;
    private MapboxMap mapboxMap;
    boolean connectedToDevice = false;
    private ImageView leftBtn;
    private ImageView rightBtn;
    TextView speedid, speeddisplay;
    Button connectbtn;
    ImageButton settingsbtn;
    public String units;
    private LocationEngine locationEngine;
    private long DEFAULT_INTERVAL_IN_MILLISECONDS = 1000L;
    private long DEFAULT_MAX_WAIT_TIME = DEFAULT_INTERVAL_IN_MILLISECONDS * 5;
    ActivityResultLauncher<Intent> someActivityResultLauncher;

    private MainActivityLocationCallback callback = new MainActivityLocationCallback(this);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Mapbox.getInstance(this, getString(R.string.mapbox_access_token));

        setContentView(R.layout.activity_main);
        units = "MPH";
        wheelsize = 1;
        mapView = findViewById(R.id.mapView);
        mapView.onCreate(savedInstanceState);
        mapView.getMapAsync(this);
        settingsbtn = findViewById(R.id.settingsbtn);
        leftBtn = findViewById(R.id.leftBtn);
        rightBtn = findViewById(R.id.rightBtn);
        connectbtn = findViewById(R.id.reconBtn);
        connectbtn.setText("Connect To Device");
        speedid = findViewById(R.id.speedlabel);
        speedid.setText(units);
        speedid.setTextSize((float)16.0);
        speeddisplay = findViewById(R.id.speeddisplay);
        speeddisplay.setTextSize((float)76.0);
        speeddisplay.setText("00");

        if (bluetoothManager == null) {
            // Bluetooth unavailable on this device
            Toast.makeText(getApplicationContext(), "Bluetooth not available.", Toast.LENGTH_LONG).show();
            finish();
        }

        settingsbtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v) {
                openSettings();
            }

        });
        connectbtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v) {
                if(connectedToDevice) {
                    bluetoothManager.closeDevice(mcu.getAddress());
                }
                Collection<BluetoothDevice> pairedDevices = bluetoothManager.getPairedDevicesList();
                boolean found = false;
                for (BluetoothDevice device : pairedDevices) {
                    //Toast.makeText(this, "Device Name: "+ device.getName(), Toast.LENGTH_LONG).show();

                    if(device.getName().contains("ESP"))
                    {

                            connectedToDevice = true;
                            found = true;
                            mcu = device;
                            break;

                    }
//            else
//            {
//                Toast.makeText(this, "ESP not found", Toast.LENGTH_LONG).show();
//            }
                }

                if(found == true)
                {
                    Toast.makeText(getApplicationContext(), "Connected to ESP32", Toast.LENGTH_SHORT).show();
                    connectDevice(mcu.getAddress());
                }
                else
                {
                    Toast.makeText(getApplicationContext(), "Connection Failed, Please Check Bluetooth Settings", Toast.LENGTH_SHORT).show();
                }



            }

        });

        someActivityResultLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                new ActivityResultCallback<ActivityResult>() {
                    @Override
                    public void onActivityResult(ActivityResult result) {
                        if (result.getResultCode() == Activity.RESULT_OK) {
                            // There are no request codes
                            Intent data = result.getData();
                            updateSettings(data.getStringExtra("unit"), data.getIntExtra("size", 1));
                        }
                    }
                });
    }



    /////BLUETOOTH METHODS///////


    private void connectDevice(String mac) {
        bluetoothManager.openSerialDevice(mac)
                .subscribeOn(Schedulers.io())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(this::onConnected, this::onError);
    }

    public void updateSettings(String unit, int size)
    {

        this.units = unit;
        this.wheelsize = size;
        speedid.setText(units);
    }


    private void onConnected(BluetoothSerialDevice connectedDevice) {
        // You are now connected to this device!
        // Here you may want to retain an instance to your device:
        deviceInterface = connectedDevice.toSimpleDeviceInterface();

        // Listen to bluetooth events
        deviceInterface.setListeners(this::onMessageReceived, this::onMessageSent, this::onError);

        // Let's send a message:
        //deviceInterface.sendMessage("Hello world!\n");
    }

    private void onMessageSent(String message) {
        // We sent a message! Handle it here.
        //Toast.makeText(this, "Sent a message! Message was: " + message, Toast.LENGTH_LONG).show(); // Replace context with your context instance.
    }

    private void calculateSpeed(String rpm)
    {

        double size = 29;
        if(wheelsize == 1)
        {
            size = 29.0;
        }
        else if(wheelsize == 2)
        {
            size = 27.5;
        }
        else if(wheelsize == 3)
        {
            size = 26.0;
        }


        char[] test = rpm.toCharArray();
        if(test.length > 2) {
            test = Arrays.copyOfRange(test, 0, test.length - 1);
        }

        int revpermin = Integer.parseInt(new String(test));

            double speed = ((double) revpermin * size * 3.14159 * 60) / 63360;
            if (units == "KPH") {
                speed = speed * 1.609;
            }

            //Toast.makeText(this, "speed is " + speed, Toast.LENGTH_SHORT).show();
            String textspeed = String.valueOf((int) speed);
            speeddisplay.setText(textspeed);


    }

    private void openSettings()
    {
        Intent intent = new Intent(MainActivity.this, SettingsActivity.class);

        intent.putExtra("unit", units);
        intent.putExtra("size", wheelsize);

        someActivityResultLauncher.launch(intent);

    }



    private void onMessageReceived(String message) {

        String[] command = message.split(" ");
        //Toast.makeText(this, "Message Recieved: " + message, Toast.LENGTH_SHORT).show();
        if(command.length == 2) {
            String messageType = command[0];
            switch (messageType) {

                case "turn":
                    if (command[1] == "left") {
                        leftBtn.setImageResource(R.drawable.ic_left_btn_on);
                        rightBtn.setImageResource(R.drawable.ic_right_btn_off);
                    } else if (command[1] == "right") {
                        leftBtn.setImageResource(R.drawable.ic_left_btn_off);
                        rightBtn.setImageResource(R.drawable.ic_right_btn_on);
                    } else if (command[1] == "off") {
                        leftBtn.setImageResource(R.drawable.ic_left_btn_off);
                        rightBtn.setImageResource(R.drawable.ic_right_btn_off);
                    }


                    break;
                case "rpm":
                    calculateSpeed(command[1]);
                    break;

                case "zero":
                    speeddisplay.setText("no");
                    break;


            }
        }


        //        // We received a message! Handle it here.
//        if(readspeed = true)
//        {
//            speeddisplay.setText(message);
//            readspeed = false;
//        }
//
//
//        else if (message.equals("x")) {
//                Toast.makeText(this, "Turn Signal Cancelled", Toast.LENGTH_SHORT).show();
//
//                RIGHT = 0;
//                LEFT = 0;
//                deviceInterface.sendMessage("o\n");
//            }
//
//        else if(message.equals("s"))
//        {
//            readspeed = true;
//        }
        //Toast.makeText(this, "Received a message! Message was: " + message, Toast.LENGTH_LONG).show(); // Replace context with your context instance.
    }

    private void onError(Throwable error) {
        // Handle the error
    }


    /////////LOCATION METHODS///////////

    @SuppressWarnings( {"MissingPermission"})
    private void enableLocationComponent(@NonNull Style loadedMapStyle) {
// Check if permissions are enabled and if not request
        if (PermissionsManager.areLocationPermissionsGranted(this)) {
// Get an instance of the component
            LocationComponent locationComponent = mapboxMap.getLocationComponent();

// Activate with options
            locationComponent.activateLocationComponent(
                    LocationComponentActivationOptions.builder(this, loadedMapStyle).build());

// Enable to make component visible
            locationComponent.setLocationComponentEnabled(true);

// Set the component's camera mode
            Toast.makeText(this,"tracking enabled", Toast.LENGTH_SHORT ).show();
            locationComponent.setCameraMode(CameraMode.TRACKING_GPS);

// Set the component's render mode
            locationComponent.setRenderMode(RenderMode.NORMAL);
            initLocationEngine();
        } else {
            permissionsManager = new PermissionsManager(this);
            permissionsManager.requestLocationPermissions(this);
        }
    }

    @SuppressLint("MissingPermission")
    private void initLocationEngine() {
        locationEngine = LocationEngineProvider.getBestLocationEngine(this);

        LocationEngineRequest request = new LocationEngineRequest.Builder(DEFAULT_INTERVAL_IN_MILLISECONDS)
                .setPriority(LocationEngineRequest.PRIORITY_HIGH_ACCURACY)
                .setMaxWaitTime(DEFAULT_MAX_WAIT_TIME).build();

        locationEngine.requestLocationUpdates(request, callback, getMainLooper());
        locationEngine.getLastLocation(callback);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {

        permissionsManager.onRequestPermissionsResult(requestCode, permissions, grantResults);
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }

    @Override
    public void onExplanationNeeded(List<String> permissionsToExplain) {
        Toast.makeText(this, "Permission", Toast.LENGTH_LONG).show();
    }



    @Override
    public void onPermissionResult(boolean granted) {
        if (granted) {
            mapboxMap.getStyle(new Style.OnStyleLoaded() {
                @Override
                public void onStyleLoaded(@NonNull Style style) {
                    enableLocationComponent(style);
                }
            });
        } else {
            Toast.makeText(this, "R.string.user_location_permission_not_granted", Toast.LENGTH_LONG).show();
            finish();
        }
    }


    private static class MainActivityLocationCallback
            implements LocationEngineCallback<LocationEngineResult> {

        private final WeakReference<MainActivity> activityWeakReference;

        MainActivityLocationCallback(MainActivity activity) {
            this.activityWeakReference = new WeakReference<>(activity);
        }

        /**
         * The LocationEngineCallback interface's method which fires when the device's location has changed.
         *
         * @param result the LocationEngineResult object which has the last known location within it.
         */
        @Override
        public void onSuccess(LocationEngineResult result) {
            MainActivity activity = activityWeakReference.get();

            if (activity != null) {
                Location location = result.getLastLocation();

                if (location == null) {
                    return;
                }

//// Create a Toast which displays the new location's coordinates
//                Toast.makeText(activity, String.format(activity.getString(R.string.new_location),
//                        String.valueOf(result.getLastLocation().getLatitude()), String.valueOf(result.getLastLocation().getLongitude())),
//                        Toast.LENGTH_SHORT).show();

// Pass the new location to the Maps SDK's LocationComponent
                if (activity.mapboxMap != null && result.getLastLocation() != null) {
                    activity.mapboxMap.getLocationComponent().forceLocationUpdate(result.getLastLocation());
                }
            }
        }

        /**
         * The LocationEngineCallback interface's method which fires when the device's location can not be captured
         *
         * @param exception the exception message
         */
        @Override
        public void onFailure(@NonNull Exception exception) {
            Log.d("LocationChangeActivity", exception.getLocalizedMessage());
            MainActivity activity = activityWeakReference.get();
            if (activity != null) {
                Toast.makeText(activity, exception.getLocalizedMessage(),
                        Toast.LENGTH_SHORT).show();
            }
        }
    }


    @Override
    protected void onStart() {
        super.onStart();
        mapView.onStart();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mapView.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mapView.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
        mapView.onStop();
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        mapView.onSaveInstanceState(outState);
    }

    @Override
    public void onLowMemory() {
        super.onLowMemory();
        mapView.onLowMemory();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        if (locationEngine != null) {
            locationEngine.removeLocationUpdates(callback);
        }
        mapView.onDestroy();
    }

    @Override
    public void onMapReady(@NonNull final MapboxMap mapboxMap) {
        MainActivity.this.mapboxMap = mapboxMap;

        mapboxMap.setStyle(new Style.Builder().fromUri("mapbox://styles/mapbox/cjerxnqt3cgvp2rmyuxbeqme7"),
                new Style.OnStyleLoaded() {
                    @Override
                    public void onStyleLoaded(@NonNull Style style) {
                        enableLocationComponent(style);
                    }
                });
    }
}

/**
 * Use the LocationComponent to easily add a device location "puck" to a Mapbox map.
 */
class LocationComponentActivity extends AppCompatActivity implements
        OnMapReadyCallback, PermissionsListener {

    private PermissionsManager permissionsManager;
    private MapboxMap mapboxMap;
    private MapView mapView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

// Mapbox access token is configured here. This needs to be called either in your application
// object or in the same activity which contains the mapview.
        Mapbox.getInstance(this, getString(R.string.mapbox_access_token));

// This contains the MapView in XML and needs to be called after the access token is configured.
        setContentView(R.layout.activity_main);

        mapView = findViewById(R.id.mapView);
        mapView.onCreate(savedInstanceState);
        mapView.getMapAsync(this);
    }

    @Override
    public void onMapReady(@NonNull final MapboxMap mapboxMap) {
        LocationComponentActivity.this.mapboxMap = mapboxMap;

        mapboxMap.setStyle(new Style.Builder().fromUri("mapbox://styles/mapbox/streets-v11"),
                new Style.OnStyleLoaded() {
                    @Override
                    public void onStyleLoaded(@NonNull Style style) {
                        enableLocationComponent(style);
                    }
                });
    }

    @SuppressWarnings( {"MissingPermission"})
    private void enableLocationComponent(@NonNull Style loadedMapStyle) {
// Check if permissions are enabled and if not request
        if (PermissionsManager.areLocationPermissionsGranted(this)) {

// Get an instance of the component
            LocationComponent locationComponent = mapboxMap.getLocationComponent();

// Activate with options
            locationComponent.activateLocationComponent(
                    LocationComponentActivationOptions.builder(this, loadedMapStyle).build());

// Enable to make component visible
            locationComponent.setLocationComponentEnabled(true);

// Set the component's camera mode
            Toast.makeText(this,"tracking enabled", Toast.LENGTH_SHORT ).show();
            locationComponent.setCameraMode(CameraMode.TRACKING);

// Set the component's render mode
            locationComponent.setRenderMode(RenderMode.NORMAL);
        } else {
            permissionsManager = new PermissionsManager(this);
            permissionsManager.requestLocationPermissions(this);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {

        permissionsManager.onRequestPermissionsResult(requestCode, permissions, grantResults);
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }

    @Override
    public void onExplanationNeeded(List<String> permissionsToExplain) {
        Toast.makeText(this, "Permission", Toast.LENGTH_LONG).show();
    }



    @Override
    public void onPermissionResult(boolean granted) {
        if (granted) {
            mapboxMap.getStyle(new Style.OnStyleLoaded() {
                @Override
                public void onStyleLoaded(@NonNull Style style) {
                    enableLocationComponent(style);
                }
            });
        } else {
            Toast.makeText(this, "R.string.user_location_permission_not_granted", Toast.LENGTH_LONG).show();
            finish();
        }
    }

    @Override
    @SuppressWarnings( {"MissingPermission"})
    protected void onStart() {
        super.onStart();
        mapView.onStart();

    }

    @Override
    protected void onResume() {
        super.onResume();
        mapView.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mapView.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
        mapView.onStop();
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        mapView.onSaveInstanceState(outState);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mapView.onDestroy();
    }

    @Override
    public void onLowMemory() {
        super.onLowMemory();
        mapView.onLowMemory();
    }
}