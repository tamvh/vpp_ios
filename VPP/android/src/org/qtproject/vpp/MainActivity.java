package org.qtproject.vpp;

/**
 * Created by thinhlt on 08/10/2016.
 */

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.os.Vibrator;
import android.content.Context;
import java.nio.ByteBuffer;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;

public class MainActivity extends org.qtproject.qt5.android.bindings.QtActivity {
    private static final String TAG = MainActivity.class.getSimpleName();

    public static MainActivity s_activity = null;
    public static int cmd = -1;
    public static int control = 0;
    public static int pwm = 0;
    public static String[] arr_password = new String[2];
    public static String[] arr_slave = new String[4];
    public static String[] arr_slave_control = new String[6];
    public static byte[] arr_cmd = new byte[4];
    public static String s_value;
    public static String s_type;
    public static String s_group;
    public static String s_number;

    public MainActivity() {
        s_activity = this;
        Log.d(TAG, "main activiti ___________________");
    }
    public static int onStartAdvertising(String slaveControl) {
        if(!slaveControl.isEmpty()) {
            arr_slave_control = slaveControl.split(":");
        }

        if (s_activity != null) {
            cmd = 0;
            s_activity.stopAdvertising();
            s_activity.startAdvertising();
        } else {
            Log.d(TAG, "Activity is NULL");
        }
        return 0;
    }
    public static int onStopAdvertising(int action) {
        Log.d(TAG, "Stop: " + action);
        s_activity.stopAdvertising();
        return 0;
    }

    public void startAdvertising() {
        Intent intent = new Intent(s_activity, AdvertiserService.class);
        startService(intent);
    }
    public void stopAdvertising() {
        Intent intent = new Intent(s_activity, AdvertiserService.class);
        stopService(intent);
    }

    public static void scanNewAdvertise() {
        s_activity.stopScanAd();
        s_activity.startScanAd();

    }
    public void startScanAd() {
        Intent intent = new Intent(s_activity, ScanAdvertiser.class);
        startService(intent);
    }
    public void stopScanAd() {
        Intent intent = new Intent(s_activity, ScanAdvertiser.class);
        stopService(intent);
    }

    public static void stopScanNewAdvertise()
    {
        s_activity.stopScanAd();
    }

}


