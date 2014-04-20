package de.dis2011.data;

import java.sql.*;

public class Estate {
    private int id;
    private String city;
    private int zip;
    private String street;
    private int street_no;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Estate setCity(String city) {
        this.city = city;
        return this;
    }

    public String getCity() {
        return this.city;
    }

    public Estate setZip(int zip) {
        this.zip = zip;
        return this;
    }

    public int getZip() {
        return this.zip;
    }

    public Estate setStreet(String street) {
        this.street = street;
        return this;
    }

    public String getStreet() {
        return this.street;
    }

    public Estate setStreetNo(int streetNo) {
        this.street_no = streetNo;
        return this;
    }

    public int getStreetNo() {
        return this.street_no;
    }
}
