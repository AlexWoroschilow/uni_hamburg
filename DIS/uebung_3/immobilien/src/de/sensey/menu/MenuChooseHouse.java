package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.menu.item.MenuItem;
import de.sensey.data.House;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuChooseHouse extends Menu {

    /**
     * @param title
     */
    public MenuChooseHouse(String title) {
        super(title);
        final ArrayList<House> collectionHouse = (new EntityManager()).getHouses();
        if (!collectionHouse.isEmpty()) {
            for (int i = 0; i < collectionHouse.size(); ++i) {
                House house = collectionHouse.get(i);
                this.addEntry("Choose: \n\t" + house, (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    return collectionHouse.get(menuItem.getCode());
                });
            }
        }
    }

    public House process() {
        try {
            return (House) super.process();
        } catch (ClassCastException ex) {
            return null;
        }
    }
}
