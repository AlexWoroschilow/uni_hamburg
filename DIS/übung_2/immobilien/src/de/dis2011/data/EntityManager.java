package de.dis2011.data;

import java.sql.*;

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
