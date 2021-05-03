package com.example.turnsignal;
import androidx.appcompat.app.AppCompatActivity;
import com.harrysoft.androidbluetoothserial.BluetoothManager;
import com.harrysoft.androidbluetoothserial.BluetoothSerialDevice;
import com.harrysoft.androidbluetoothserial.SimpleBluetoothDeviceInterface;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
//import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.os.ParcelUuid;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothServerSocket;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.util.Set;
import java.util.UUID;

import io.reactivex.android.schedulers.AndroidSchedulers;
import io.reactivex.schedulers.Schedulers;

public class MainActivity extends AppCompatActivity {

    private SimpleBluetoothDeviceInterface deviceInterface;
    BluetoothManager bluetoothManager = BluetoothManager.getInstance();
    BluetoothDevice mcu;
    private byte LEFT = 0;
    private byte RIGHT = 0;
    ImageButton mleftBtn, mrightBtn;
    Button mreconBtn;
   // BluetoothAdapter bluetoothAdapter;
    private OutputStream outputStream;
    private InputStream inStream;


    @Override
    protected void onCreate(Bundle savedInstanceState) {


        if (bluetoothManager == null) {
            // Bluetooth unavailable on this device
            Toast.makeText(getApplicationContext(), "Bluetooth not available.", Toast.LENGTH_LONG).show();
            finish();
        }

        Collection<BluetoothDevice> pairedDevices = bluetoothManager.getPairedDevicesList();
        //Toast.makeText(this, "paired devices: " + pairedDevices.size(), Toast.LENGTH_LONG).show();

        for (BluetoothDevice device : pairedDevices) {
            //Toast.makeText(this, "Device Name: "+ device.getName(), Toast.LENGTH_LONG).show();
            if(device.getName().contains("ESP"))
            {
                Toast.makeText(getApplicationContext(), "Connected to ESP32", Toast.LENGTH_LONG).show();
                mcu = device;
            }
//            else
//            {
//                Toast.makeText(this, "ESP not found", Toast.LENGTH_LONG).show();
//            }
        }

        Toast.makeText(this, "Named: " + mcu.getName(), Toast.LENGTH_LONG).show();

        connectDevice(mcu.getAddress());

        //deviceInterface.sendMessage("HELLO");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mleftBtn = findViewById(R.id.leftBtn);
        mrightBtn = findViewById(R.id.rightBtn);
        mreconBtn = findViewById(R.id.reconBtn);
        mreconBtn.setText("Reconnect to ESP32");

        mleftBtn.setImageResource(R.drawable.ic_left_off);
        mrightBtn.setImageResource(R.drawable.ic_right_off);
        mreconBtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v) {
                bluetoothManager.closeDevice(mcu.getAddress());
                Collection<BluetoothDevice> pairedDevices = bluetoothManager.getPairedDevicesList();
                for (BluetoothDevice device : pairedDevices) {
                    //Toast.makeText(this, "Device Name: "+ device.getName(), Toast.LENGTH_LONG).show();
                    if(device.getName().contains("ESP"))
                    {
                        Toast.makeText(getApplicationContext(), "Connected to ESP32", Toast.LENGTH_SHORT).show();
                        mcu = device;
                    }
//            else
//            {
//                Toast.makeText(this, "ESP not found", Toast.LENGTH_LONG).show();
//            }
                }

                Toast.makeText(getApplicationContext(), "Named: " + mcu.getName(), Toast.LENGTH_SHORT).show();

                connectDevice(mcu.getAddress());

            }

        });
        mleftBtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v) {
                if(LEFT == 0)
                {
                    mleftBtn.setImageResource(R.drawable.ic_left_on);
                    mrightBtn.setImageResource(R.drawable.ic_right_off);
                    LEFT = 1;
                    RIGHT = 0;
                    deviceInterface.sendMessage("l\n");

                }
                else
                {
                    mleftBtn.setImageResource(R.drawable.ic_left_off);
                    LEFT = 0;
                    deviceInterface.sendMessage("o\n");
                }

            }

        });


        mrightBtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v) {
                if(RIGHT == 0)
                {
                    mrightBtn.setImageResource(R.drawable.ic_right_on);
                    mleftBtn.setImageResource(R.drawable.ic_left_off);
                    RIGHT = 1;
                    LEFT = 0;
                    deviceInterface.sendMessage("r\n");
                }
                else
                {
                    mrightBtn.setImageResource(R.drawable.ic_right_off);
                    RIGHT = 0;
                    deviceInterface.sendMessage("o\n");
                }

            }

        });
    }

    private void connectDevice(String mac) {
        bluetoothManager.openSerialDevice(mac)
                .subscribeOn(Schedulers.io())
                .observeOn(AndroidSchedulers.mainThread())
                .subscribe(this::onConnected, this::onError);
    }
//
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

    private void onMessageReceived(String message) {
        // We received a message! Handle it here.
        if(message.equals("x"))
        {
            Toast.makeText(this,"Turn Signal Cancelled", Toast.LENGTH_SHORT).show();
            mleftBtn.setImageResource(R.drawable.ic_left_off);
            mrightBtn.setImageResource(R.drawable.ic_right_off);
            RIGHT = 0;
            LEFT = 0;
            deviceInterface.sendMessage("o\n");
        }
        //Toast.makeText(this, "Received a message! Message was: " + message, Toast.LENGTH_LONG).show(); // Replace context with your context instance.
    }

    private void onError(Throwable error) {
        // Handle the error
    }




}
