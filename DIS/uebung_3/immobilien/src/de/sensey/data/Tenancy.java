package de.sensey.data;

import java.util.Date;

public class Tenancy {
    private int id;
    private int contract_no;
    private Date date;
    private String place;
    private Date start;
    private int duration;
    private float additional_costs;
    private Apartment estate;
    private Person person;

    public Person getPerson() {
        return person;
    }

    public Tenancy setPerson(Person person) {
        this.person = person;
        return this;
    }

    public Apartment getEstate() {
        return estate;
    }

    public Tenancy setEstate(Apartment estate) {
        this.estate = estate;
        return this;
    }


    public float getAdditional_costs() {
        return additional_costs;
    }

    public Tenancy setAdditional_costs(float additional_costs) {
        this.additional_costs = additional_costs;
        return this;
    }

    public int getId() {
        return id;
    }

    public Tenancy setId(int id) {
        this.id = id;
        return this;
    }

    public int getContract_no() {
        return contract_no;
    }

    public Tenancy setContract_no(int contract_no) {
        this.contract_no = contract_no;
        return this;
    }

    public Date getDate() {
        return date;
    }

    public Tenancy setDate(Date date) {
        this.date = date;
        return this;

    }

    public String getPlace() {
        return place;
    }

    public Tenancy setPlace(String place) {
        this.place = place;
        return this;

    }

    public Date getStart() {
        return start;
    }

    public Tenancy setStart(Date start) {
        this.start = start;
        return this;
    }

    public int getDuration() {
        return duration;
    }

    public Tenancy setDuration(int duration) {
        this.duration = duration;
        return this;
    }

    /**
     * Convert object to string
     *
     * @return
     */
    public String toString() {

        return new String(
                "\n\t Started: " + this.getStart()
        );
    }

}
