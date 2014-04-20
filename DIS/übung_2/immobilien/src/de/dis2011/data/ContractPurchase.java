package de.dis2011.data;

import java.sql.*;

public class ContractPurchase {
    private int id;
    private Sell sell;
    private Contract contract;
    private int installment_count;
    private int rate;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Sell getSell() {
        return this.sell;
    }

    public ContractPurchase setSell(Sell sell) {
        this.sell = sell;
        return this;
    }

    public Contract getContract() {
        return this.contract;
    }

    public ContractPurchase setContract(Contract contract) {
        this.contract = contract;
        return this;
    }

    public int getInstallmentCount() {
        return this.installment_count;
    }

    public ContractPurchase setInstallmentCount(int installmentCount) {
        this.installment_count = installmentCount;
        return this;
    }

    public int getRate() {
        return this.rate;
    }

    public ContractPurchase setRate(int rate) {
        this.rate = rate;
        return this;
    }

    public String toString() {

        return new String(
                "\n\t Rate: " +
                        this.getRate() +
                        "\n\t Sell: \n\t" +
                        this.getSell() +
                        "\n\t Contract: \n\t" +
                        this.getContract() +
                        "\n\t Installment count: " +
                        this.getInstallmentCount()
        );
    }
}