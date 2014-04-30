package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.menu.item.MenuItem;
import de.sensey.data.Apartment;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuChooseApartment extends Menu {

    /**
     * @param title
     */
    public MenuChooseApartment(String title) {
        super(title);
        final ArrayList<Apartment> collection = (new EntityManager()).getApartments();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                Apartment apartment = collection.get(i);
                this.addEntry("Choose: \n\t" + apartment, (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    return collection.get(menuItem.getCode());
                });
            }
        }
    }

    public Apartment process() {
        try {
            return (Apartment) super.process();
        } catch (ClassCastException ex) {
            return null;
        }
    }
}
