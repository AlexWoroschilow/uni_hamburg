package de.dis2011.data;

import java.sql.*;

public class ContractPurchase {
    private int id;
    private Contract contract;
    private Sell sell;
    private int installment_count;
    private int rate;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
