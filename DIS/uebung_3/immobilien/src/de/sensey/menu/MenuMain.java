package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.FormUtil;

/**
 * Created by studi on 30.04.14.
 */
public class MenuMain extends Menu {

    public MenuMain(String title) {
        super(title);

        this.addEntry("Manage agents", (item) -> {
            return (Boolean) this.onManageAgentsMenu(item);
        }).addEntry("Manage estates", (item) -> {
            return (Boolean) this.onManageEstatesMenu(item);
        }).addEntry("Manage contracts", (item) -> {
            return (Boolean) this.onManageContractsMenu(item);
        }).addEntry("Exit", (item) -> {
            return false;
        });
    }

    /**
     * @param item
     * @return
     */
    protected Object onManageAgentsMenu(Object item) {
        EntityManager entityManager = new EntityManager();
        String login = FormUtil.readString("Login");
        String password = FormUtil.readString("Password");
        if (entityManager.loginAsManager(login, password)) {
            System.out.println("Authentication success!");

            while (
                    (Boolean)
                            (new MenuAgents("Main menu >> Manage agents"))
                                    .process()
                    ) ;

            return true;
        }
        System.out.println("Manager account not found.");
        System.out.println("Pair of login and password was wrong.");
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onManageEstatesMenu(Object item) {
        EntityManager entityManager = new EntityManager();
        String login = FormUtil.readString("Login");
        String password = FormUtil.readString("Password");
        if (entityManager.loginAsEstateAgent(login, password)) {
            System.out.println("Authentication success!");
            MenuEstates menu = new MenuEstates("Main menu >> Manage estates");
            while ((Boolean) menu.process()) ;
            return true;
        }
        System.out.println("Estate agent account not found.");
        System.out.println("Pair of login and password was wrong.");
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onManageContractsMenu(Object item) {
        EntityManager entityManager = new EntityManager();
        String login = FormUtil.readString("Login");
        String password = FormUtil.readString("Password");
        if (entityManager.loginAsEstateAgent(login, password)) {
            System.out.println("Authentication success!");
            MenuContracts menu = new MenuContracts("Main menu >> Manage contracts");
            while ((Boolean) menu.process()) ;
            return true;
        }
        System.out.println("Estate agent account not found.");
        System.out.println("Pair of login and password was wrong.");
        return true;
    }


}
