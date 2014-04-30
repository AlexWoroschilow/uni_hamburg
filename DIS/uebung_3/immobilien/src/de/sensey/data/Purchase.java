package de.sensey.data;

import java.util.Date;

public class Purchase {
    private int id;
    private int contract_no;
    private Date date;
    private String place;
    private int rate;
    private int installment_count;
    private House estate;
    private Person person;

    public int getId() {
        return id;
    }

    public Purchase setId(int id) {
        this.id = id;
        return this;
    }

    public int getContract_no() {
        return contract_no;
    }

    public Purchase setContract_no(int contract_no) {
        this.contract_no = contract_no;
        return this;
    }

    public Date getDate() {
        return date;
    }

    public Purchase setDate(Date date) {
        this.date = date;
        return this;
    }

    public String getPlace() {
        return place;
    }

    public Purchase setPlace(String place) {
        this.place = place;
        return this;
    }

    public int getRate() {
        return rate;
    }

    public Purchase setRate(int rate) {
        this.rate = rate;
        return this;
    }

    public int getInstallment_count() {
        return installment_count;
    }

    public Purchase setInstallment_count(int installment_count) {
        this.installment_count = installment_count;
        return this;
    }

    public Person getPerson() {
        return person;
    }

    public Purchase setPerson(Person person) {
        this.person = person;
        return this;
    }

    public House getEstate() {
        return estate;
    }

    public Purchase setEstate(House estate) {
        this.estate = estate;
        return this;
    }

    public String toString() {

        return new String(
                "\n\t Rate: " + this.getRate()
        );
    }
}