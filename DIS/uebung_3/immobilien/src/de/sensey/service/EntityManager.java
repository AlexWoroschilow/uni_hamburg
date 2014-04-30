package de.sensey.service;

import de.sensey.data.*;

import java.util.ArrayList;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

public class EntityManager {

    private SessionFactory sessionFactory;

    public EntityManager() {
        sessionFactory = new Configuration().configure().buildSessionFactory();
    }

    public ArrayList<Purchase> getContractsPurchase() {
        ArrayList<Purchase> collection = new ArrayList<Purchase>();

//        collection.add(
//                (new Purchase())
//                        .setSell(
//                                (new Sell())
//                                        .setHouse(
//                                                (new House())
//                                                        .setEstate(new Estate())
//                                                        .setFloorCount(12)
//                                                        .setIsGarden(1)
//                                                        .setPrice(123000)
//                                                        .setCity("Hamburg")
//                                                        .setStreet("Bundesstrasse")
//                                        )
//                                        .setPerson(
//                                                (new Person())
//                                                        .setName("Person 1")
//                                                        .setFirstName("Alex")
//                                        )
//                        )
//                        .setContract(
//                                (new Contract())
//                                        .setContractNo(23423413)
//                                        .setDate(new Date())
//                                        .setPlace("test place")
//                        )
//                        .setInstallmentCount(12)
//                        .setRate(23)
//        );
        return collection;
    }

    public ArrayList<Tenancy> getContractsTenancy() {
        ArrayList<Tenancy> collection = new ArrayList<Tenancy>();
//        collection.add(
//                (new Tenancy())
//                        .setRent(
//                                (new Rent())
//                                        .setApartment(
//                                                (new Apartment())
//                                                        .setEstate(new Estate())
//                                                        .setFloor(1)
//                                                        .setIsKitchen(true)
//                                                        .setIsBalcony(true)
//                                                        .setRoomCount(12)
//                                                        .setCity("Hamburg")
//                                                        .setStreet("Bundesstrasse")
//                                                        .setStreetNo(42)
//                                        )
//                                        .setPerson(
//                                                (new Person())
//                                                        .setName("Person 1")
//                                                        .setFirstName("Alex")
//                                        )
//                        ).setContract(
//                        (new Contract())
//                                .setContractNo(423452345)
//                                .setDate(new Date())
//                                .setPlace("Test place")
//                ).setDuration(12)
//                        .setAdditionalCost(12)
//                        .setStartedAt(new Date())
//        );

        return collection;
    }

    public ArrayList<Person> getPersons() {
        ArrayList<Person> collection = new ArrayList<Person>();
//
//        collection.add(
//                (new Person())
//                        .setName("Person 1")
//        );
//        collection.add(
//                (new Person())
//                        .setName("Person 2")
//        );
//        collection.add(
//                (new Person())
//                        .setName("Person 3")
//        );

        return collection;
    }


//    public Estate getEstate(int id) {
//        return null;
//    }

    public ArrayList<House> getHouses() {

        ArrayList<House> collection = new ArrayList<House>();

        return collection;
    }

    public ArrayList<Apartment> getApartments() {

        ArrayList<Apartment> collection = new ArrayList<Apartment>();
//
//        collection.add(
//                (new Apartment())
//                        .setEstate(
//                                (new Estate())
//                                        .setCity("Hamburg")
//                                        .setStreet("Grindelhoff")
//                                        .setStreetNo(12)
//                                        .setZip(24254)
//                        )
//                        .setIsBalcony(true)
//                        .setIsKitchen(true)
//                        .setFloor(4)
//                        .setRent(700)
//                        .setRoomCount(3)
//        );

        return collection;
    }

    public ArrayList<Agent> getEstateAgents() {

        ArrayList<Agent> collection = new ArrayList<Agent>();

        collection.add(
                (new Agent())
                        .setId(1)
                        .setName("Test 1")
        );

        collection.add(
                (new Agent())
                        .setId(2)
                        .setName("Test 2")
        );

        return collection;
    }

    public boolean loginAsManager(String login, String password) {

        return true;
    }

    public boolean loginAsEstateAgent(String login, String password) {

        return true;
    }

    public void remove(Agent entity) {

    }

    public void remove(House entity) {

    }

    public void remove(Apartment entity) {

    }


    public void persist(Agent agent) {
        Session session = sessionFactory.openSession();
        session.beginTransaction();
        session.save(agent);
        session.getTransaction().commit();
    }


    public void persist(House entity) {
    }

    public void persist(Apartment entity) {
    }


    public void persist(Purchase entity) {

    }

    public void persist(Tenancy entity) {
    }

    public void persist(Person entity) {
    }
}
