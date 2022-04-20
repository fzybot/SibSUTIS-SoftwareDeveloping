package com.example.resourcesmedia;

public class Song {

    private String fileName;
    private int duration;

    public void setFileName(String name){
        this.fileName = name;
    }

    public void setDuration(int duration){
        this.duration = duration;
    }

    public String getFileName(){
        return this.fileName;
    }

    public int getDuration(){
        return this.duration;
    }
}
