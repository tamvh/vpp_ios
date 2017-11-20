package org.qtproject.vpp;

/**
 * Created by Thinhlt on 28/3/2017.
 */

import android.annotation.TargetApi;
import android.app.Service;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothManager;
import android.bluetooth.le.AdvertiseCallback;
import android.bluetooth.le.AdvertiseData;
import android.bluetooth.le.AdvertiseSettings;
import android.bluetooth.le.BluetoothLeAdvertiser;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Handler;
import android.os.IBinder;
import android.util.Log;
import android.widget.Toast;
import android.app.Notification;
import android.app.NotificationManager;

import java.io.Console;
import java.lang.reflect.Array;
import java.util.concurrent.TimeUnit;
import java.util.ArrayList;
import android.app.Activity;



public class ScanAdvertiser extends Service{
    private BluetoothAdapter mBluetoothAdapter;
    private Handler mHandler;
    private boolean mScanning;
    private int check = 0;
    private static long SCAN_PERIOD = 1000000;


    @Override
    public void onCreate() {
        Log.d("ScanAd", "onCreate Advertiser Service");
        final BluetoothManager bluetoothManager =
                (BluetoothManager) getSystemService(Context.BLUETOOTH_SERVICE);
        mBluetoothAdapter = bluetoothManager.getAdapter();

        // Checks if Bluetooth is supported on the device.
        if (mBluetoothAdapter == null) {

            return;
        }
        scanLeDevice(true);
        super.onCreate();
    }

    @Override
    public void onDestroy() {
        Log.d("ScanAd", "onDestroy Advertiser Service");
        scanLeDevice(false);
        super.onDestroy();
    }
    private void scanLeDevice(final boolean enable) {
        Log.d("DeviceScanActivity", "scan ble on class: ");
        if (enable) {
            mScanning = true;
            mBluetoothAdapter.startLeScan(mLeScanCallback);
        } else {
            mScanning = false;
            mBluetoothAdapter.stopLeScan(mLeScanCallback);
        }
    }
    private BluetoothAdapter.LeScanCallback mLeScanCallback =
            new BluetoothAdapter.LeScanCallback() {
                @Override
                public void onLeScan(final BluetoothDevice device, int rssi, byte[] scanRecord) {

//                    String msg = device.getAddress().toString() ;//ByteArrayToString(scanRecord);
//                    MyJavaNatives.sendAdvertiseData(device.getName(),device.getAddress(), rssi);


                }

            };


    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
    public static String ByteArrayToString(byte[] ba)
     {
         StringBuilder hex = new StringBuilder(ba.length * 2);
         for (byte b : ba)
             hex.append(String.format("%02x",b));

         return hex.toString();
     }

    /**
     * Get references to system Bluetooth objects if we don't have them already.
     */


}
//class MyJavaNatives {
//    public static native void sendAdvertiseData(String name,String address ,int rssi);
//}
