package de.dis2011.data;

import java.sql.*;

/**
 * EstateAgent-Bean
 * <p>
 * Beispiel-Tabelle:
 * CREATE TABLE makler(id INTEGER NOT NULL GENERATED ALWAYS AS IDENTITY (START WITH 1, INCREMENT BY 1, NO CACHE) PRIMARY KEY,
 * name varchar(255),
 * address varchar(255),
 * login varchar(40) UNIQUE,
 * password varchar(40));
 */
public class Person {
    private int id;
    private String name;
    private String first_name;
    private String address;

    public int getId() {
        return this.id;
    }

    public Person setId(int id) {
        this.id = id;
        return this;
    }

    public String getName() {
        return this.name;
    }

    public Person setName(String name) {
        this.name = name;
        return this;
    }

    public String getFirstName() {
        return this.first_name;
    }

    public Person setFirstName(String first_name) {
        this.first_name = first_name;
        return this;
    }

    public String getAddress() {
        return this.address;
    }

    public Person setAddress(String address) {
        this.address = address;
        return this;
    }

    public String toString() {
        return new String(
                "\t\t Name: " +
                        this.getName() +
                        "\n\t\t\t Address: " +
                        this.getAddress()
        );
    }
}
