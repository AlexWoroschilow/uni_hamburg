package de.dis2011.data;

import java.sql.*;

public class House {
    private int id;
    private int floor_count;
    private float price;
    private boolean is_garden;
    private Estate estate;

    public int getId() {
        return id;
    }

    public House setId(int id) {
        this.id = id;
        return this;
    }

    public House setFloorCount(int floorCount) {
        this.floor_count = floorCount;
        return this;
    }

    public int getFloorCount() {
        return this.floor_count;
    }

    public House setPrice(float price) {
        this.price = price;
        return this;
    }

    public float getPrice() {
        return this.price;
    }

    public House setEstate(Estate estate) {
        this.estate = estate;
        return this;
    }

    public Estate getEstate() {
        return this.estate;
    }

    public House setIsGarden(boolean isGarden) {
        this.is_garden = isGarden;
        return this;
    }

    public boolean getIsGarden() {
        return this.is_garden;
    }
}
