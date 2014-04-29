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

    public String getCity() {
        return this.getEstate().getCity();
    }

    public Apartment setCity(String city) {
        this.getEstate().setCity(city);
        return this;
    }

    public int getZip() {
        return this.getEstate().getZip();
    }

    public Apartment setZip(int zip) {
        this.getEstate().setZip(zip);
        return this;
    }

    public String getStreet() {
        return this.getEstate().getStreet();
    }

    public Apartment setStreet(String street) {
        this.getEstate().setStreet(street);
        return this;
    }

    public int getStreetNo() {
        return this.getEstate().getStreetNo();
    }

    public Apartment setStreetNo(int streetNo) {
        this.getEstate().setStreetNo(streetNo);
        return this;
    }

    public String toString() {
        return new String(
                "\t\t Zip: " +
                        this.getZip() +
                        "\n\t\t\t City: " +
                        this.getCity() +
                        "\n\t\t\t Street: " +
                        this.getStreet() +
                        "\n\t\t\t Street No: " +
                        this.getStreetNo() +
                        "\n\t\t\t Floor: " +
                        this.getFloor() +
                        "\n\t\t\t Has kitchen: " +
                        this.getIsKitchen() +
                        "\n\t\t\t Has balcon: " +
                        this.getIsBalcony()
        );
    }
}
