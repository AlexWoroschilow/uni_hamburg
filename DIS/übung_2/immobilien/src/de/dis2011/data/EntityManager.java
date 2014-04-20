package de.dis2011.data;

import de.dis2011.FormUtil;

import java.sql.*;
import java.util.*;
import java.util.Date;

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
public class EntityManager {
    public ArrayList<ContractPurchase> getContractsPurchase() {
        ArrayList<ContractPurchase> collection = new ArrayList<ContractPurchase>();

        collection.add(
                (new ContractPurchase())
                        .setSell(
                                (new Sell())
                                        .setHouse(
                                                (new House())
                                                        .setEstate(new Estate())
                                                        .setFloorCount(12)
                                                        .setIsGarden(true)
                                                        .setPrice(123000)
                                                        .setCity("Hamburg")
                                                        .setStreet("Bundesstrasse")
                                        )
                                        .setPerson(
                                                (new Person())
                                                        .setName("Person 1")
                                                        .setFirstName("Alex")
                                        )
                        )
                        .setContract(
                                (new Contract())
                                        .setContractNo(23423413)
                                        .setDate(new Date())
                                        .setPlace("test place")
                        )
                        .setInstallmentCount(12)
                        .setRate(23)
        );
        return collection;
    }

    public ArrayList<ContractTenancy> getContractsTenancy() {
        ArrayList<ContractTenancy> collection = new ArrayList<ContractTenancy>();
        collection.add(
                (new ContractTenancy())
                        .setRent(
                                (new Rent())
                                        .setApartment(
                                                (new Apartment())
                                                        .setEstate(new Estate())
                                                        .setFloor(1)
                                                        .setIsKitchen(true)
                                                        .setIsBalcony(true)
                                                        .setRoomCount(12)
                                                        .setCity("Hamburg")
                                                        .setStreet("Bundesstrasse")
                                                        .setStreetNo(42)
                                        )
                                        .setPerson(
                                                (new Person())
                                                        .setName("Person 1")
                                                        .setFirstName("Alex")
                                        )
                        ).setContract(
                        (new Contract())
                                .setContractNo(423452345)
                                .setDate(new Date())
                                .setPlace("Test place")
                ).setDuration(12)
                        .setAdditionalCost(12)
                        .setStartedAt(new Date())
        );

        return collection;
    }

    public ArrayList<Person> getPersons() {
        ArrayList<Person> collection = new ArrayList<Person>();

        collection.add(
                (new Person())
                        .setName("Person 1")
        );
        collection.add(
                (new Person())
                        .setName("Person 2")
        );
        collection.add(
                (new Person())
                        .setName("Person 3")
        );

        return collection;
    }

    public ArrayList<House> getHouses() {

        ArrayList<House> collection = new ArrayList<House>();

        collection.add(
                (new House())
                        .setEstate(
                                (new Estate())
                                        .setCity("Hamburg")
                                        .setStreet("Bundesstrasse")
                                        .setStreetNo(42)
                                        .setZip(24254)
                        )
                        .setFloorCount(3)
                        .setIsGarden(true)
                        .setPrice(120000)
        );
        return collection;
    }

    public ArrayList<Apartment> getApartments() {

        ArrayList<Apartment> collection = new ArrayList<Apartment>();

        collection.add(
                (new Apartment())
                        .setEstate(
                                (new Estate())
                                        .setCity("Hamburg")
                                        .setStreet("Grindelhoff")
                                        .setStreetNo(12)
                                        .setZip(24254)
                        )
                        .setIsBalcony(true)
                        .setIsKitchen(true)
                        .setFloor(4)
                        .setRent(700)
                        .setRoomCount(3)
        );

        return collection;
    }

    public ArrayList<EstateAgent> getEstateAgents() {

        ArrayList<EstateAgent> collection = new ArrayList<EstateAgent>();

        collection.add(
                (new EstateAgent())
                        .setId(1)
                        .setName("Test 1")
        );

        collection.add(
                (new EstateAgent())
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

    public void remove(EstateAgent entity) {

    }

    public void remove(House entity) {

    }

    public void remove(Apartment entity) {

    }

    public void persist(EstateAgent entity) {
    }

    public void persist(Estate entity) {
    }

    public void persist(House entity) {
    }

    public void persist(Apartment entity) {
    }

    public void persist(Contract entity) {
    }

    public void persist(ContractPurchase entity) {
    }

    public void persist(ContractTenancy entity) {
    }

    public void persist(Person entity) {
    }

    public void persist(Rent entity) {
    }

    public void persist(Sell entity) {
    }

    /**
     * Speichert den EstateAgent in der Datenbank. Ist noch keine ID vergeben
     * worden, wird die generierte Id von DB2 geholt und dem Model übergeben.
     */
    public void save() {
//        // Hole Verbindung
//        Connection con = DB2ConnectionManager.getInstance().getConnection();
//
//        try {
//            // FC<ge neues Element hinzu, wenn das Objekt noch keine ID hat.
//            if (getId() == -1) {
//                // Achtung, hier wird noch ein Parameter mitgegeben,
//                // damit spC$ter generierte IDs zurC<ckgeliefert werden!
//                String insertSQL = "INSERT INTO makler(name, address, login, password) VALUES (?, ?, ?, ?)";
//
//                PreparedStatement pstmt = con.prepareStatement(insertSQL,
//                        Statement.RETURN_GENERATED_KEYS);
//
//                // Setze Anfrageparameter und fC<hre Anfrage aus
//                pstmt.setString(1, getName());
//                pstmt.setString(2, getAddress());
//                pstmt.setString(3, getLogin());
//                pstmt.setString(4, getPassword());
//                pstmt.executeUpdate();
//
//                // Hole die Id des engefC<gten Datensatzes
//                ResultSet rs = pstmt.getGeneratedKeys();
//                if (rs.next()) {
//                    setId(rs.getInt(1));
//                }
//
//                rs.close();
//                pstmt.close();
//            } else {
//                // Falls schon eine ID vorhanden ist, mache ein Update...
//                String updateSQL = "UPDATE makler SET name = ?, address = ?, login = ?, password = ? WHERE id = ?";
//                PreparedStatement pstmt = con.prepareStatement(updateSQL);
//
//                // Setze Anfrage Parameter
//                pstmt.setString(1, getName());
//                pstmt.setString(2, getAddress());
//                pstmt.setString(3, getLogin());
//                pstmt.setString(4, getPassword());
//                pstmt.setInt(5, getId());
//                pstmt.executeUpdate();
//
//                pstmt.close();
//            }
//        } catch (SQLException e) {
//            e.printStackTrace();
//        }
    }
}
