package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.FormUtil;
import de.sensey.data.Person;

/**
 * Created by studi on 30.04.14.
 */
public class MenuContracts extends Menu {

    public MenuContracts(String title) {
        super(title);

        this.addEntry("Create person", (item) -> {
            return (Boolean) this.onCreatePerson(item);
        }).addEntry("Create contract", (item) -> {
            return (Boolean) this.onCreateContract(item);
        }).addEntry("Show all contracts", (item) -> {
            return (Boolean) this.onShowContracts(item);
        }).addEntry("Previous menu", (item) -> {
            return false;
        });
    }

    /**
     * @param item
     * @return
     */
    protected Object onCreatePerson(Object item) {
        (new EntityManager()).persist(
                (new Person())
                        .setName_first(FormUtil.readString("First name"))
                        .setName_last(FormUtil.readString("Last name"))
                        .setAddress(FormUtil.readString("Address"))
        );
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onCreateContract(Object item) {
        MenuContractCreate menu = new MenuContractCreate(
                "Main menu >> Manage contracts >> Create contract"
        );
        while ((Boolean) menu.process()) ;
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onShowContracts(Object item) {
        MenuContractShow menu = new MenuContractShow(
                "Main menu >> Manage contracts >> Show contracts"
        );
        while ((Boolean) menu.process()) ;
        return true;
    }


}
