package de.sensey.menu;

import de.sensey.data.Agent;
import de.sensey.data.Apartment;
import de.sensey.menu.item.MenuItem;
import de.sensey.service.EntityManager;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuChooseAgent extends Menu {

    /**
     * @param title
     */
    public MenuChooseAgent(String title) {
        super(title);
        final ArrayList<Agent> collection = (new EntityManager()).getAgents();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                Agent agent = collection.get(i);
                this.addEntry("Choose: \n\t" + agent, (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    return collection.get(menuItem.getCode());
                });
            }
        }
    }

    public Agent process() {
        try {
            return (Agent) super.process();
        } catch (ClassCastException ex) {
            return null;
        }
    }
}
