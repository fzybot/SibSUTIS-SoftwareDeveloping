package com.example.resourcesmedia;

import android.content.Context;
import android.database.Cursor;
import android.provider.MediaStore;

import java.util.ArrayList;
import java.util.List;

public class MusicScanner {

    public static List<Song> getMusicList(Context context){

        List<Song> list = new ArrayList<>();

        Cursor cursor = context.getContentResolver().query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, null, null, null,
                MediaStore.Audio.AudioColumns.IS_MUSIC);
        if(cursor != null){
            while (cursor.moveToNext()){
                Song foundSong = new Song();
                foundSong.setFileName(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.DISPLAY_NAME)));
                foundSong.setDuration(cursor.getInt(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.DURATION)));
            }
            cursor.close();
        }
        return list;
    }
}
