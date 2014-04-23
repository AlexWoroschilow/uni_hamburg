package de.dis2011.data;

import java.sql.*;
import java.util.ArrayList;
import java.util.Date;

import static java.sql.Statement.RETURN_GENERATED_KEYS;

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


    public Estate getEstate(int id) {
        try {
            // Hole Verbindung
            Connection con = DB2ConnectionManager.getInstance().getConnection();

            // Erzeuge Anfrage
            String selectSQL = "SELECT * FROM estate WHERE id = ?";
            PreparedStatement pstmt = con.prepareStatement(selectSQL);
            pstmt.setInt(1, id);

            // Führe Anfrage aus
            ResultSet rs = pstmt.executeQuery();
            if (rs.next()) {

                Estate ts = (new Estate())
                        .setCity(rs.getString("city"))
                        .setStreet(rs.getString("city"))
                        .setStreetNo(rs.getInt("street_no"))
                        .setZip(rs.getInt("zip"));

                rs.close();
                pstmt.close();
                return ts;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    public ArrayList<House> getHouses() {

        ArrayList<House> collection = new ArrayList<House>();

        try {
            // Hole Verbindung
            Connection con = DB2ConnectionManager.getInstance().getConnection();

            PreparedStatement pstmt = con.prepareStatement("SELECT * FROM house");

            // Führe Anfrage aus
            ResultSet rs = pstmt.executeQuery();
            while (rs.next()) {

                collection.add(
                        (new House())
                                .setEstate(getEstate(rs.getInt("estate_id")))
                                .setFloorCount(rs.getInt("floor_count"))
                                .setIsGarden(rs.getBoolean("is_garden"))
                                .setPrice(rs.getFloat("price"))
                );
            }

            rs.close();
            pstmt.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

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

        Connection connection = DB2ConnectionManager.getInstance().getConnection();

        EstateAgent estateAgent = entity;


        try {

            PreparedStatement pstmtEstate = connection
                    .prepareStatement("INSERT INTO estate_agent(name, address, login, password, estate_id) VALUES (?, ?, ?, ?, ?)",
                            RETURN_GENERATED_KEYS);

            pstmtEstate.setString(1, estateAgent.getName());
            pstmtEstate.setString(2, estateAgent.getAddress());
            pstmtEstate.setString(3, estateAgent.getLogin());
            pstmtEstate.setString(4, estateAgent.getPassword());
            pstmtEstate.setInt(4, estateAgent.getEstate().getId());

            ResultSet rs = pstmtEstate.getGeneratedKeys();
            if (rs.next()) {
                estateAgent.setId(rs.getInt(1));
            }
            rs.close();
            pstmtEstate.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }


    }

    public void persist(Estate entity) {
    }

    public void persist(House entity) {

        Connection connection = DB2ConnectionManager.getInstance().getConnection();

        House house = entity;
        Estate estate = house.getEstate();

        try {

            PreparedStatement pstmtEstate = connection
                    .prepareStatement("INSERT INTO estate(zip, city, street, street_no) VALUES (?, ?, ?, ?)",
                            RETURN_GENERATED_KEYS);

            pstmtEstate.setInt(1, estate.getZip());
            pstmtEstate.setString(2, estate.getCity());
            pstmtEstate.setString(3, estate.getStreet());
            pstmtEstate.setInt(4, estate.getStreetNo());
            pstmtEstate.executeUpdate();

            ResultSet rs = pstmtEstate.getGeneratedKeys();
            if (rs.next()) {
                estate.setId(rs.getInt(1));
            }
            rs.close();
            pstmtEstate.close();

            PreparedStatement pstmt = connection
                    .prepareStatement("INSERT INTO house(estate_id, floor_count, price, is_garden) VALUES (?, ?, ?, ?)",
                            RETURN_GENERATED_KEYS);

            pstmt.setInt(1, estate.getId());
            pstmt.setInt(2, house.getFloorCount());
            pstmt.setFloat(3, house.getPrice());
            pstmt.setBoolean(4, house.getIsGarden());
            pstmt.executeUpdate();

            ResultSet rs2 = pstmtEstate.getGeneratedKeys();
            if (rs2.next()) {
                house.setId(rs2.getInt(1));
            }
            rs2.close();
            pstmt.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
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

        Connection connection = DB2ConnectionManager.getInstance().getConnection();

        Person person = entity;

        try {

            PreparedStatement pstmt = connection
                    .prepareStatement("INSERT INTO person(name, name_first, address) VALUES (?, ?, ?)");

            pstmt.setString(1, person.getName());
            pstmt.setString(2, person.getFirstName());
            pstmt.setString(3, person.getAddress());

            pstmt.executeUpdate();
            pstmt.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void persist(Rent entity) {
    }

    public void persist(Sell entity) {
    }


//    protected void save(String sql)

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
