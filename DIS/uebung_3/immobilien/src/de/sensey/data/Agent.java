package de.sensey.data;

import java.util.Set;

public class Agent {
    private int id;
    private String name;
    private String address;
    private String login;
    private String password;
    private Set<House> houses;

    public Set<Apartment> getApartments() {
        return apartments;
    }

    public void setApartments(Set<Apartment> apartments) {
        this.apartments = apartments;
    }

    public Set<House> getHouses() {
        return houses;
    }

    public void setHouses(Set<House> houses) {
        this.houses = houses;
    }

    private Set<Apartment> apartments;


    /**
     * @return
     */
    public int getId() {
        return id;
    }

    /**
     * @param id
     * @return
     */
    public Agent setId(int id) {
        this.id = id;
        return this;
    }

    /**
     * @return
     */
    public String getName() {
        return name;
    }

    /**
     * @param name
     * @return
     */
    public Agent setName(String name) {
        this.name = name;
        return this;
    }

    /**
     * @return
     */
    public String getAddress() {
        return address;
    }

    /**
     * @param address
     * @return
     */
    public Agent setAddress(String address) {
        this.address = address;
        return this;
    }

    /**
     * @return
     */
    public String getLogin() {
        return login;
    }

    /**
     * @param login
     * @return
     */
    public Agent setLogin(String login) {
        this.login = login;
        return this;
    }

    public String getPassword() {
        return password;
    }

    /**
     * @param password
     * @return
     */
    public Agent setPassword(String password) {
        this.password = password;
        return this;
    }
}
