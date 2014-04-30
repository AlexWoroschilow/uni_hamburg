package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.menu.item.MenuItem;
import de.sensey.data.Apartment;
import de.sensey.data.House;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuEstateDelete extends Menu {

    public MenuEstateDelete(String title) {
        super(title);

        final ArrayList<House> collectionHouse = (new EntityManager()).getHouses();
        if (!collectionHouse.isEmpty()) {
            for (int i = 0; i < collectionHouse.size(); ++i) {
                House estate = collectionHouse.get(i);
                this.addEntry("House: \n\t" + estate, (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    House entity = collectionHouse.get(menuItem.getCode());
                    return (Boolean) this.onDeleteHouse(entity);
                });
            }
        }
        final ArrayList<Apartment> collectionApartment = (new EntityManager()).getApartments();
        if (!collectionApartment.isEmpty()) {
            for (int i = 0; i < collectionApartment.size(); ++i) {
                Apartment estate = collectionApartment.get(i);
                this.addEntry("Apartment: \n\t" + estate, (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    Apartment entity = collectionApartment.get(menuItem.getCode());
                    return (Boolean) this.onDeleteApartment(entity);
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
    protected Object onDeleteHouse(House house) {
        (new EntityManager()).remove(house);
        return true;
    }

    /**
     * @param apartment
     * @return
     */
    protected Object onDeleteApartment(Apartment apartment) {
        (new EntityManager()).remove(apartment);
        return true;
    }
}
