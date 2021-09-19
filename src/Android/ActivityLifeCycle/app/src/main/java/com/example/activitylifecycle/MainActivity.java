package com.example.activitylifecycle;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    /*
        Задание на лабораторную работу №1:
            1. Создать еще 2 текстовых поля.
            2. Изменить размер\цвет\шрифт текстовых полей для каждого из циклов жизни Activity.
            3. Случайным образом менять позицию текстовых полей (по X и Y координатам) при смене жизненного цикла. 
            Поля не должны пересекаться друг с другом.
    */

    private String TAG = "Life Cycle";
    TextView testText;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        testText = (TextView) findViewById(R.id.textView);
        testText.setText("onCreate() - on");
        Log.i(TAG, (String) testText.getText());
    }

    @Override
    protected void onStart() {
        super.onStart();
        testText.setText("onStar() - on");
        Log.i(TAG, (String) testText.getText());
    }

    @Override
    protected void onResume() {
        super.onResume();

        testText.setText("onResume() - on");
        Log.i(TAG, (String) testText.getText());
    }

    @Override
    protected void onPause() {
        super.onPause();

        testText.setText("onPause() - on");
        Log.i(TAG, (String) testText.getText());
    }

    @Override
    protected void onStop() {
        super.onStop();

        testText.setText("onStop() - on");
        Log.i(TAG, (String) testText.getText());
    }

    @Override
    protected void onRestart() {
        super.onRestart();

        testText.setText("onRestart() - on");
        Log.i(TAG, (String) testText.getText());
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        testText.setText("onDestroy() - on");
        Log.i(TAG, (String) testText.getText());
    }
}