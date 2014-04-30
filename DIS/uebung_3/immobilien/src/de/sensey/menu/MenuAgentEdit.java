package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.FormUtil;
import de.sensey.menu.item.MenuItem;
import de.sensey.data.Agent;

import java.util.ArrayList;

/**
 * Created by studi on 30.04.14.
 */
public class MenuAgentEdit extends Menu {

    public MenuAgentEdit(String title) {
        super(title);
        final ArrayList<Agent> collection = (new EntityManager()).getAgents();
        if (!collection.isEmpty()) {
            for (int i = 0; i < collection.size(); ++i) {
                Agent agent = collection.get(i);
                this.addEntry("Edit: " + agent.getName(), (item) -> {
                    MenuItem menuItem = (MenuItem) item;
                    Agent entity = collection.get(menuItem.getCode());
                    return (Boolean) this.onEditAgent(entity);
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
    protected Object onEditAgent(Agent agent) {
        (new EntityManager()).persist(
                agent.setName(FormUtil.readString("Name (" + agent.getName() + ")"))
                        .setAddress(FormUtil.readString("Address (" + agent.getAddress() + ")"))
                        .setLogin(FormUtil.readString("Login (" + agent.getLogin() + ")"))
                        .setPassword(FormUtil.readString("Password"))
        );

        return true;
    }
}
