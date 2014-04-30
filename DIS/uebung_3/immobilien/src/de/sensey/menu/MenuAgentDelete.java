package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.menu.item.MenuItem;
import de.sensey.data.Agent;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuAgentDelete extends Menu {

    public MenuAgentDelete(String title) {
        super(title);
        final ArrayList<Agent> collection = (new EntityManager()).getEstateAgents();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                Agent agent = collection.get(i);
                this.addEntry("Remove: " + agent.getName(), (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    Agent entity = collection.get(menuItem.getCode());
                    return (Boolean) this.onDeleteAgent(entity);
                });
            }
        }
        this.addEntry("Previous menu", (item) -> {
            return false;
        });
    }

    /**
     * @param agent
     * @return
     */
    protected Object onDeleteAgent(Agent agent) {
        (new EntityManager()).remove(agent);
        return true;
    }
}
