package com.example.screenelements;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

import java.io.IOException;


/*
    TODO:
    - Заменить seekBar на progressBar
    - Заставить progressBar перемещаться во время проигрывания песни
    - Добавить seekBar по регулировки громкости
    - Добавить функционал нажатия\отжатия кнопок
    - Добавить функцию зацикливания одного трека
 */

public class MainActivity extends AppCompatActivity implements View.OnClickListener, SeekBar.OnSeekBarChangeListener{

    private String TAG = "Life Cycle";

    MediaPlayer mPlayer;
    TextView textView, currPos;
    SeekBar cPosition;
    Button bPlay, bPause, bStop;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.i(TAG, (String) "onCreate() method");

        textView = findViewById(R.id.songName);
        currPos = findViewById(R.id.currPosition);

        cPosition = findViewById(R.id.seekPos);

        mPlayer = MediaPlayer.create(this, R.raw.music_test);
        bPlay = findViewById(R.id.buttonPlay);
        bPause = findViewById(R.id.buttonPause);
        bStop = findViewById(R.id.buttonStop);

        // Первый вариант обработки нажатия кнопок.
        bPlay.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                textView.setText("First case: " + String.valueOf(mPlayer.getDuration()));
                play();
                cPosition.setMax(mPlayer.getDuration());
            }
        });

        // Второй вариант обработки нажатия кнопок.
        bPause.setOnClickListener(this);
        cPosition.setOnSeekBarChangeListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.buttonPause:
                textView.setText("Second case: Pause");
                pause();
                break;
        }
    }

    public void stop(View view) throws IOException {
        textView.setText("Third case: Stop");
        mPlayer.stop();
        mPlayer.prepare();
        mPlayer.seekTo(0);
    }
    public void play(){
        mPlayer.start();
    }
    public void pause(){
        mPlayer.pause();
    }


    @Override
    public void onProgressChanged(SeekBar seekBar, int i, boolean b) {


    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
        currPos.setText(String.valueOf(cPosition.getProgress()));
        mPlayer.seekTo(cPosition.getProgress());
    }
}