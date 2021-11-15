package com.example.bikestuff;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.preference.PreferenceFragmentCompat;

public class SettingsActivity extends AppCompatActivity {

    RadioButton mphbtn;
    RadioButton kphbtn;
    RadioButton size29;
    RadioButton size27;
    RadioButton size26;
    RadioGroup unitgroup;
    RadioGroup sizegroup;
    Button savebtn;
    String unit;
    int size;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.settings_activity);
//        ActionBar actionBar = getSupportActionBar();
//        if (actionBar != null) {
//            actionBar.setDisplayHomeAsUpEnabled(true);
//        }

        mphbtn = findViewById(R.id.milesbtn);
        kphbtn = findViewById(R.id.kilobtn);
        size29 = findViewById(R.id.size29);
        size27 = findViewById(R.id.size275);
        size26 = findViewById(R.id.size26);
        unitgroup = findViewById(R.id.unitgroup);
        sizegroup = findViewById(R.id.sizegroup);
        savebtn = findViewById(R.id.buttonsave);
        Intent i = getIntent();
        unit = i.getStringExtra("unit");
        size = i.getIntExtra("size", 1);

        switch(unit)
        {
            case "MPH":
                mphbtn.setChecked(true);
                kphbtn.setChecked(false);
                break;

            case "KPH":
                mphbtn.setChecked(false);
                kphbtn.setChecked(true);
                break;
        }

        switch(size)
        {
            case 1:
                size29.setChecked(true);
                size27.setChecked(false);
                size26.setChecked(false);
                break;

            case 2:
                size27.setChecked(true);
                size29.setChecked(false);
                size26.setChecked(false);
                break;
            case 3:
                size26.setChecked(true);
                size27.setChecked(false);
                size29.setChecked(false);
                break;

        }

        unitgroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener()
        {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                // checkedId is the RadioButton selected
                RadioButton rb = findViewById(checkedId);
                //Toast.makeText(getApplicationContext(), rb.getText(), Toast.LENGTH_SHORT).show();
                if(rb.getText().equals("Miles"))
                {
                      unit = "MPH";
                    Toast.makeText(getApplicationContext(), "Changed to MPH", Toast.LENGTH_SHORT).show();
                }
                else if(rb.getText().equals("Kilometers"))
                {
                    unit = "KPH";
                    Toast.makeText(getApplicationContext(), "Changed to KPH", Toast.LENGTH_SHORT).show();
                }
            }
        });

        sizegroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener()
        {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                RadioButton rb = findViewById(checkedId);
                String check = rb.getText().toString();
                switch (check)
                {
                    case "29\" / 700c":
                        size = 1;
                        Toast.makeText(getApplicationContext(), "Wheel Size is set to 29\" / 700c", Toast.LENGTH_SHORT).show();
                        break;
                    case "27.5\" / 650b":
                        size = 2;
                        Toast.makeText(getApplicationContext(), "Wheel Size is set to 27.5\" / 650b", Toast.LENGTH_SHORT).show();
                        break;
                    case "26\"":
                        size = 3;
                        Toast.makeText(getApplicationContext(), "Wheel Size is set to 26\"", Toast.LENGTH_SHORT).show();
                        break;
                }
            }
        });

//        mphbtn.setOnClickListener(new View.OnClickListener()
//        {
//            @Override
//            public void onClick(View v) {
//                if(!mphbtn.isChecked())
//                {
//                    unit = "MPH";
//                    mphbtn.setChecked(true);
//                    kphbtn.setChecked(false);
//
//                }
//            }
//
//        });
//
//        kphbtn.setOnClickListener(new View.OnClickListener()
//        {
//            @Override
//            public void onClick(View v) {
//                if(!kphbtn.isChecked())
//                {
//                    unit = "KPH";
//                    kphbtn.setChecked(true);
//                    mphbtn.setChecked(false);
//
//                }
//            }
//
//        });
//
//        size29.setOnClickListener(new View.OnClickListener()
//        {
//            @Override
//            public void onClick(View v) {
//                if(!size29.isChecked())
//                {
//                    size = 1;
//                    size29.setChecked(true);
//                    size27.setChecked(false);
//                    size26.setChecked(false);
//
//                }
//            }
//
//        });
//
//        size27.setOnClickListener(new View.OnClickListener()
//        {
//            @Override
//            public void onClick(View v) {
//                if(!size27.isChecked())
//                {
//                    size = 2;
//                    size27.setChecked(true);
//                    size29.setChecked(false);
//                    size26.setChecked(false);
//
//                }
//            }
//
//        });
//
//        size26.setOnClickListener(new View.OnClickListener()
//        {
//            @Override
//            public void onClick(View v) {
//                if(!size26.isChecked())
//                {
//                    size = 3;
//                    size26.setChecked(true);
//                    size27.setChecked(false);
//                    size29.setChecked(false);
//
//                }
//            }
//
//        });

        savebtn.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.putExtra("unit", unit);
                intent.putExtra("size", size);
                setResult(RESULT_OK, intent);
                finish();
            }

        });


    }

}