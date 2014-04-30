package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.FormUtil;
import de.sensey.data.Agent;

/**
 * Created by studi on 30.04.14.
 */
public class MenuAgents extends Menu {

    public MenuAgents(String title) {
        super(title);

        this.addEntry("Create account", (item) -> {
            return (Boolean) this.onCreateAgent(item);
        }).addEntry("Modify account", (item) -> {
            return (Boolean) this.onEditAgent(item);
        }).addEntry("Delete account", (item) -> {
            return (Boolean) this.onDeleteAgent(item);
        }).addEntry("Previous menu", (item) -> {
            return false;
        });
    }

    /**
     * @param item
     * @return
     */
    protected Object onCreateAgent(Object item) {
        (new EntityManager()).persist(
                (new Agent()).setName(FormUtil.readString("Name"))
                        .setAddress(FormUtil.readString("Address"))
                        .setLogin(FormUtil.readString("Login"))
                        .setPassword(FormUtil.readString("Password"))
        );
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onEditAgent(Object item) {
        MenuAgentEdit menu = new MenuAgentEdit(
                "Main menu >> Manage agents >> Edit agent"
        );
        while ((Boolean) menu.process()) ;
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onDeleteAgent(Object item) {
        MenuAgentDelete menu = new MenuAgentDelete(
                "Main menu >> Manage agents >> Delete agent"
        );
        while ((Boolean) menu.process()) ;
        return true;
    }
}
