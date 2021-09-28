package com.example.lifecycleaudioexample;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.view.View.OnClickListener;
import android.widget.SeekBar;

import java.io.IOException;

/*
    Задание на лабораторную работу №2:
        1. Логично произвести взаимодествие с плеером по циклу жизни Activity:
            1.1. При закрытии из приложения нажимать на паузу.
            1.2. При возобновлении приложения продолжить воспроизведение трека.
        2. Создать "ползунок" для перехода на определенную секунду трека\мелодии. (ДЛЯ ПРОДВИНУТЫХ)
        3. Вывести на экран время трека, текущюю позицию воспроизведения.
        4. Создать текстовое поле (или изменить текст кнопок) при переходе из режима воспроизведения
            в режим паузы и наоборот.
*/

public class MainActivity extends AppCompatActivity implements OnClickListener{

    MediaPlayer myPlayer;
    Button play, pause, stop;
    SeekBar volume;
    AudioManager audioManager;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myPlayer = MediaPlayer.create(this, R.raw.test);

        play = (Button) findViewById(R.id.playAudio);
        pause = (Button) findViewById(R.id.pauseAudio);
        stop = (Button) findViewById(R.id.stopAudio);

        play.setOnClickListener((OnClickListener) this);
        pause.setOnClickListener((OnClickListener) this);
        stop.setOnClickListener((OnClickListener) this);

        // Взаимодействие с аудио: пока нам нужна информация о громкости.
        audioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
        int maxVolume = audioManager.getStreamMaxVolume(AudioManager.STREAM_MUSIC);
        int curValue = audioManager.getStreamVolume(AudioManager.STREAM_MUSIC);

        // Создание и работа с ползунком.
        volume = (SeekBar) findViewById(R.id.volumeControl);
        volume.setMax(maxVolume);
        volume.setProgress(curValue);
        // Обработка действий при изменении ползунка в реальном времени.
        volume.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                audioManager.setStreamVolume(AudioManager.STREAM_MUSIC, progress, 0);
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }

    // Функция обработка нажатия на какую либо из кнопок в нашем окне (Activity).
    @Override
    public void onClick(View v){
        switch (v.getId()) {
            case R.id.playAudio:
                startPlay();
                break;
            case R.id.pauseAudio:
                pausePlay();
                break;
            case R.id.stopAudio:
                try {
                    stopPlay();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                break;
        }
    }

    // Функции взаимодействия с плеером.
    private void startPlay() {
        myPlayer.start();
    }

    private void pausePlay() {
        myPlayer.pause();
    }

    private void stopPlay() throws IOException {
        myPlayer.stop();
        myPlayer.prepare();
    }
}