package de.dis2011.data;

import java.sql.*;


public class Contract {
    private int id;
    private int contract_no;
    private Date date;
    private String place;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
