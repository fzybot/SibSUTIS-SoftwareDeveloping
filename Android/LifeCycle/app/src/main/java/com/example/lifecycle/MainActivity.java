package com.example.lifecycle;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;


/*
Задание:
1. Доработать воспроизведение музыки с учетом жизненного цикла Activity
2. Попробовать найти и добавить функционал управления громкостью.
3. Правильно обрабатывать нажатие кнопки Stop.
4. Добавить отслеживание в реальном времени текущей секунды воспроизведения.
5. Для настойчивых. Добавить возможность считывать плейлист из папки с музыкой.
 */

public class MainActivity extends AppCompatActivity {

    private String TAG = "Life Cycle";

    MediaPlayer mPlayer;
    Button bPlay, bPause, bStop;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.i(TAG, (String) "onCreate() method");

        mPlayer = MediaPlayer.create(this, R.raw.music_test);
        bPlay = findViewById(R.id.buttonPlay);
        bPause = findViewById(R.id.buttonPause);
        bStop = findViewById(R.id.buttonStop);


    }

    @Override
    protected  void onStart() {
        super.onStart();

        Log.i(TAG, (String) "onStart() method");
    }

    @Override
    protected  void onPause() {
        super.onPause();

        Log.i(TAG, (String) "onPause() method");
    }

    @Override
    protected  void onResume() {
        super.onResume();

        Log.i(TAG, (String) "onResume() method");
    }

    @Override
    protected  void onStop() {
        super.onStop();

        Log.i(TAG, (String) "onStop() method");
    }

    public void stop(View view){
        mPlayer.stop();
    }
    public void play(View view){
        mPlayer.start();
        //Log.i(TAG, String.valueOf(mPlayer.getTrackInfo()));
    }
    public void pause(View view){
        mPlayer.pause();
    }







}