package de.sensey.menu;

import de.sensey.data.Agent;
import de.sensey.service.EntityManager;
import de.sensey.FormUtil;
import de.sensey.data.Apartment;
import de.sensey.data.House;

/**
 * Created by studi on 30.04.14.
 */
public class MenuEstateCreate extends Menu {

    /**
     * @param title
     */
    public MenuEstateCreate(String title) {
        super(title);
        this.addEntry("Create house", (item) -> {
            return (Boolean) this.onCreateHouse(item);
        }).addEntry("Create apartment", (item) -> {
            return (Boolean) this.onCreateApartment(item);
        }).addEntry("Previous menu", (item) -> {
            return false;
        });
    }

    /**
     * @param item
     * @return
     */
    protected Object onCreateHouse(Object item) {
        (new EntityManager()).persist(
                (new House())
                        .setAgent((Agent) (new MenuChooseAgent("Choose agent")).process())
                        .setZip(FormUtil.readString("Zip"))
                        .setCity(FormUtil.readString("City"))
                        .setStreet(FormUtil.readString("Street"))
                        .setStreet_no(FormUtil.readString("Street No"))
                        .setSquare(FormUtil.readString("Square"))
                        .setFloor_count(FormUtil.readInt("Floor count"))
                        .setIs_garden(FormUtil.readBoolean("Has garden") ? 1 : 0)
                        .setPrice(FormUtil.readFloat("Price"))
        );
        return true;
    }

    /**
     * @param item
     * @return0
     */
    protected Object onCreateApartment(Object item) {
        (new EntityManager()).persist(
                (new Apartment()).setFloor(FormUtil.readInt("Floor"))
                        .setAgent((Agent) (new MenuChooseAgent("Choose agent")).process())
                        .setZip(FormUtil.readString("Zip"))
                        .setCity(FormUtil.readString("City"))
                        .setStreet(FormUtil.readString("Street"))
                        .setStreet_no(FormUtil.readString("Street No"))
                        .setSquare(FormUtil.readString("Square"))
                        .setRoom_count(FormUtil.readInt("Room count"))
                        .setIs_balcony(FormUtil.readBoolean("Has balcon") ? 1 : 0)
                        .setIs_kitchen(FormUtil.readBoolean("Has kitchen") ? 1 : 0)
                        .setRent(FormUtil.readFloat("Rent"))
        );

        return true;
    }

}
