package com.example.resourcesmedia;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import java.util.List;

/*
    TODO:
    1. Доработать класс Song (сохранять более точную информацию).
    2. Доработать класс MusicScanner (фильтровать по папкам, по размеру файла (чтобы не было рингтонов)).
    3. Создать класс, позволяющий отображать список песен на экране (в ListView при помощи Adapter'а ).
 */

public class MainActivity extends AppCompatActivity {
    String LOG_TAG = "myList";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        List<Song> list = MusicScanner.getMusicList(MainActivity.this);
        for(int i = 0; i < list.size(); i++){
            Log.i(LOG_TAG, "Found song --> " + list.get(i).getFileName());
        }
    }
}