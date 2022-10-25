package com.bgcottrell.tuneit;
import android.media.AudioManager;
import android.media.AudioDeviceInfo;
import android.content.Context;
import android.widget.Toast;
public class AudioDevices {
    public static int getDefaultInputDevice(Context ctx) {
        AudioManager mgr = (AudioManager)ctx.getSystemService(android.content.Context.AUDIO_SERVICE);
        return mgr.getDevices(AudioManager.GET_DEVICES_INPUTS)[0].getId();
    }
    public static int myfun(Context ctx) {
        //Toast.makeText(ctx, "calling myfun", android.widget.Toast.LENGTH_SHORT);
        AudioManager mgr = (AudioManager)ctx.getSystemService(android.content.Context.AUDIO_SERVICE);
        return mgr.getDevices(AudioManager.GET_DEVICES_INPUTS)[0].getId();
    }
}
