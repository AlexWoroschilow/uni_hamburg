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
public class Sell {
    private int id;
    private House house;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

}
