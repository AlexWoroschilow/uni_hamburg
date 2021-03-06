package de.sensey.menu;

import de.sensey.data.Agent;
import de.sensey.service.EntityManager;
import de.sensey.FormUtil;
import de.sensey.menu.item.MenuItem;
import de.sensey.data.Apartment;
import de.sensey.data.House;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuEstateEdit extends Menu {

    /**
     * @param title
     */
    public MenuEstateEdit(String title) {
        super(title);
        final ArrayList<House> collectionHouse = (new EntityManager()).getHouses();
        if (!collectionHouse.isEmpty()) {
            for (int i = 0; i < collectionHouse.size(); ++i) {
                House house = collectionHouse.get(i);
                this.addEntry("House: \n\t" + house, (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    House entity = collectionHouse.get(menuItem.getCode());
                    return (Boolean) this.onEditHouse(entity);
                });
            }
        }
        final ArrayList<Apartment> collectionApartment = (new EntityManager()).getApartments();
        if (!collectionApartment.isEmpty()) {
            for (int i = 0; i < collectionApartment.size(); ++i) {
                Apartment apartment = collectionApartment.get(i);
                this.addEntry("Apartment: \n\t" + apartment, (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    Apartment entity = collectionApartment.get(menuItem.getCode());
                    return (Boolean) this.onEditApartment(entity);
                });
            }
        }

        this.addEntry("Previous menu", (item) -> {
            return false;
        });
    }

    /**
     * @param house
     * @return
     */
    protected Object onEditHouse(House house) {
        (new EntityManager()).persist(
                house
                        .setAgent((Agent) (new MenuChooseAgent("Choose agent (" + house.getAgent() + ")")).process())
                        .setCity(FormUtil.readString("City (" + house.getCity() + ")"))
                        .setZip(FormUtil.readString("Zip (" + house.getZip() + ")"))
                        .setStreet(FormUtil.readString("Street (" + house.getStreet() + ")"))
                        .setStreet_no(FormUtil.readString("Street No (" + house.getStreet_no() + ")"))
                        .setFloor_count(FormUtil.readInt("Floors (" + house.getFloor_count() + ")"))
                        .setIs_garden(FormUtil.readInt("Has Garden (" + house.getIs_garden() + ")"))
                        .setPrice(FormUtil.readFloat("Price (" + house.getPrice() + ")"))
        );

        return true;
    }

    /**
     * @param apartment
     * @return
     */
    protected Object onEditApartment(Apartment apartment) {

        (new EntityManager()).persist(
                apartment
                        .setAgent((Agent) (new MenuChooseAgent("Choose agent (" + apartment.getAgent() + ")")).process())
                        .setZip(FormUtil.readString("Zip (" + apartment.getZip() + ")"))
                        .setCity(FormUtil.readString("City (" + apartment.getCity() + ")"))
                        .setStreet(FormUtil.readString("Street (" + apartment.getStreet() + ")"))
                        .setStreet_no(FormUtil.readString("Street No (" + apartment.getStreet_no() + ")"))
                        .setFloor(FormUtil.readInt("Floor (" + apartment.getFloor() + ")"))
                        .setRoom_count(FormUtil.readInt("Rooms (" + apartment.getRoom_count() + ")"))
                        .setIs_balcony(FormUtil.readBoolean("Has Balcon (" + apartment.getIs_balcony() + ")") ? 1 : 0)
                        .setIs_kitchen(FormUtil.readBoolean("Has Kitchen (" + apartment.getIs_kitchen() + ")") ? 1 : 0)
                        .setRent(FormUtil.readFloat("Rent (" + apartment.getRent() + ")"))
        );
        return true;
    }


}
