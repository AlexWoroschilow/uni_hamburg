package de.sensey.data;

public class Person {
    private int id;
    private String name_first;
    private String name_last;
    private String address;

    public int getId() {
        return id;
    }

    public Person setId(int id) {
        this.id = id;
        return this;
    }

    public String getName_first() {
        return name_first;
    }

    public Person setName_first(String name_first) {
        this.name_first = name_first;
        return this;
    }

    public String getName_last() {
        return name_last;
    }

    public Person setName_last(String name_last) {
        this.name_last = name_last;
        return this;
    }

    public String getAddress() {
        return address;
    }

    public Person setAddress(String address) {
        this.address = address;
        return this;
    }
}
