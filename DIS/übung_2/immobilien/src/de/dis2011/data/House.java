package de.dis2011.data;

import java.sql.*;

public class House {
    private int id;
    private int floor_count;
    private float price;
    private int is_garden;
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

    public Estate getEstate() {
        return this.estate;
    }

    public House setEstate(Estate estate) {
        this.estate = estate;
        return this;
    }

    public House setIsGarden(int isGarden) {
        this.is_garden = isGarden;
        return this;
    }

    public int getIsGarden() {
        return this.is_garden;
    }


    public String getCity() {
        return this.getEstate().getCity();
    }

    public House setCity(String city) {
        this.getEstate().setCity(city);
        return this;
    }

    public int getZip() {
        return this.getEstate().getZip();
    }

    public House setZip(int zip) {
        this.getEstate().setZip(zip);
        return this;
    }

    public String getStreet() {
        return this.getEstate().getStreet();
    }

    public House setStreet(String street) {
        this.getEstate().setStreet(street);
        return this;
    }

    public int getStreetNo() {
        return this.getEstate().getStreetNo();
    }

    public House setStreetNo(int streetNo) {
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
                        "\n\t\t\t Price: " +
                        this.getPrice() +
                        "\n\t\t\t Has garden: " +
                        this.getIsGarden() +
                        "\n\t\t\t Floor count: " +
                        this.getFloorCount()
        );
    }

}
