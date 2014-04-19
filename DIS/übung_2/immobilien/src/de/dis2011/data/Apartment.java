package de.dis2011.data;

import java.sql.*;

public class Apartment {
    private int id;
    private Estate estate;
    private int floor;
    private float rent;
    private int room_count;
    private boolean is_balcony;
    private boolean is_kitchen;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Apartment setFloor(int floor) {
        this.floor = floor;
        return this;
    }

    public int getFloor() {
        return this.floor;
    }

    public Apartment setRent(float rent) {
        this.rent = rent;
        return this;
    }

    public float getRent() {
        return this.rent;
    }

    public Apartment setRoomCount(int roomCount) {
        this.room_count = roomCount;
        return this;
    }

    public int getRoomCount() {
        return this.room_count;
    }

    public Apartment setIsBalcony(boolean isBalcony) {
        this.is_balcony = isBalcony;
        return this;
    }

    public boolean getIsBalcony() {
        return this.is_balcony;
    }

    public Apartment setIsKitchen(boolean isKitchen) {
        this.is_kitchen = isKitchen;
        return this;
    }

    public boolean getIsKitchen() {
        return this.is_kitchen;
    }

    public Apartment setEstate(Estate estate) {
        this.estate = estate;
        return this;
    }

    public Estate getEstate() {
        return this.estate;
    }

}
