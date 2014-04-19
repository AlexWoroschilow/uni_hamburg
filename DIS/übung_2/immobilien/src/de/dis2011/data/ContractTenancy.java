package de.dis2011.data;

import java.sql.*;

public class ContractTenancy {
    private int id;
    private Date started_at;
    private float duration;
    private float additional_costs;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
