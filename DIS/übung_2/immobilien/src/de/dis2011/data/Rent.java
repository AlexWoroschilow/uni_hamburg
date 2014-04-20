package de.dis2011.data;

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
public class Rent {
    private int id;
    private Apartment apartment;
    private Person person;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Apartment getApartment() {
        return this.apartment;
    }

    public Rent setApartment(Apartment apartment) {
        this.apartment = apartment;
        return this;
    }

    public Person getPerson() {
        return this.person;
    }

    public Rent setPerson(Person person) {
        this.person = person;
        return this;
    }

    public String toString() {
        return new String(
                "\t Apartment: \n\t" +
                        this.getApartment() +
                        "\n\t\t Person: \n\t" +
                        this.getPerson()
        );
    }
}
