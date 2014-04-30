package de.sensey.service;

import de.sensey.data.*;

import java.util.ArrayList;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

public class EntityManager {

    private SessionFactory sessionFactory = null;

    public EntityManager() {
        if (sessionFactory == null) {
            sessionFactory = new Configuration().configure().buildSessionFactory();
        }
    }

    /**
     * @return
     */
    public ArrayList<Purchase> getContractsPurchase() {

        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();

        ArrayList<Purchase> collection = (ArrayList<Purchase>) session
                .createQuery("from Purchase")
                .list();

        session.getTransaction().commit();

        return collection;
    }

    /**
     * @return
     */
    public ArrayList<Tenancy> getContractsTenancy() {

        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();

        ArrayList<Tenancy> collection = (ArrayList<Tenancy>) session
                .createQuery("from Tenancy")
                .list();

        session.getTransaction().commit();

        return collection;
    }

    /**
     * @return
     */
    public ArrayList<Person> getPersons() {

        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();

        ArrayList<Person> collection = (ArrayList<Person>) session
                .createQuery("from Person")
                .list();

        session.getTransaction().commit();

        return collection;
    }


    /**
     * @return
     */
    public ArrayList<House> getHouses() {

        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();

        ArrayList<House> collection = (ArrayList<House>) session
                .createQuery("from House")
                .list();

        session.getTransaction().commit();

        return collection;
    }

    /**
     * @return
     */
    public ArrayList<Apartment> getApartments() {

        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();

        ArrayList<Apartment> collection = (ArrayList<Apartment>) session
                .createQuery("from Apartment")
                .list();

        session.getTransaction().commit();

        return collection;
    }

    /**
     * @return
     */
    public ArrayList<Agent> getAgents() {

        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();

        ArrayList<Agent> collection = (ArrayList<Agent>) session
                .createQuery("from Agent")
                .list();

        session.getTransaction().commit();

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


    /**
     * Create or update Agent object
     *
     * @param agent
     */
    public void persist(Agent agent) {
        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        session.merge(agent);
        session.getTransaction().commit();
    }


    /**
     * Create or update House object
     *
     * @param house
     */
    public void persist(House house) {
        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        session.merge(house);
        session.getTransaction().commit();
    }

    /**
     * Create or update Apartment object
     *
     * @param apartment
     */
    public void persist(Apartment apartment) {
        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        session.merge(apartment);
        session.getTransaction().commit();
    }

    /**
     * Create or update Purchase object
     *
     * @param purchase
     */
    public void persist(Purchase purchase) {
        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        session.merge(purchase);
        session.getTransaction().commit();
    }

    /**
     * Create or update Tenancty object
     *
     * @param tenancy
     */
    public void persist(Tenancy tenancy) {
        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        session.save(tenancy);
        session.getTransaction().commit();
    }

    /**
     * Create or update Person object
     *
     * @param person
     */
    public void persist(Person person) {
        Session session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        session.save(person);
        session.getTransaction().commit();
    }
}
