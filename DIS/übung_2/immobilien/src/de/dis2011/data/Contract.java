package de.dis2011.data;

import java.sql.*;
import java.util.Date;


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

    public Date getDate() {
        return this.date;
    }

    public Contract setDate(Date date) {
        this.date = date;
        return this;
    }

    public String getPlace() {
        return this.place;
    }

    public Contract setPlace(String place) {
        this.place = place;
        return this;
    }

    public int getContractNo() {
        return this.contract_no;
    }

    public Contract setContractNo(int contractNo) {
        this.contract_no = contractNo;
        return this;
    }

    public String toString() {
        return new String(
                "\t Contract No: " +
                        this.getContractNo() +
                        "\n\t\t Date: " +
                        this.getDate() +
                        "\n\t\t Place: " +
                        this.getPlace()
        );
    }

}
