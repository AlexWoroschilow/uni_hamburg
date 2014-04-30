package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.menu.item.MenuItem;
import de.sensey.data.Person;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuChoosePerson extends Menu {

    /**
     * @param title
     */
    public MenuChoosePerson(String title) {
        super(title);
        final ArrayList<Person> collection = (new EntityManager()).getPersons();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                Person person = collection.get(i);
                this.addEntry("Choose: \n\t" + person, (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    return collection.get(menuItem.getCode());
                });
            }
        }
    }

    public Person process() {
        try {
            return (Person) super.process();
        } catch (ClassCastException ex) {
            return null;
        }
    }
}
