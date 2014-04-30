package de.sensey.menu;

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
                (new House()).setFloor_count(FormUtil.readInt("Floor count"))
                        .setPrice(FormUtil.readFloat("Price"))
                        .setIs_garden(FormUtil.readInt("Has garden"))
        );
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onCreateApartment(Object item) {
        (new EntityManager()).persist(
                (new Apartment()).setFloor(FormUtil.readInt("Floor"))
                        .setRoom_count(FormUtil.readInt("Room count"))
                        .setRent(FormUtil.readFloat("Rent"))
                        .setIs_balcony(FormUtil.readBoolean("Has balcon"))
                        .setIs_kitchen(FormUtil.readBoolean("Has kitchen"))
        );

        return true;
    }

}
