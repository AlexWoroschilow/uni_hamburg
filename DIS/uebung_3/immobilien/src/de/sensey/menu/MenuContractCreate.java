package de.sensey.menu;

import de.sensey.service.EntityManager;
import de.sensey.FormUtil;
import de.sensey.data.Purchase;
import de.sensey.data.Tenancy;

/**
 * Created by studi on 30.04.14.
 */
public class MenuContractCreate extends Menu {

    public MenuContractCreate(String title) {
        super(title);

        this.addEntry("Create purchase contract", (item) -> {
            return (Boolean) this.onCreateContractPurchase(item);
        }).addEntry("Create tenancy contract", (item) -> {
            return (Boolean) this.onCreateContractTenancy(item);
        }).addEntry("Previous menu", (item) -> {
            return false;
        });
    }

    /**
     * @param item
     * @return
     */
    protected Object onCreateContractPurchase(Object item) {

        (new EntityManager()).persist(
                (new Purchase()).setContract_no(FormUtil.readInt("Contract No"))
                        .setPlace(FormUtil.readString("Place"))
                        .setDate(FormUtil.readDate("Date ('MMMM d, yyyy')"))
                        .setInstallment_count(FormUtil.readInt("Installment count"))
                        .setRate(FormUtil.readInt("Rate"))
                        .setEstate((new MenuChooseHouse("Choose house")).process())
                        .setPerson((new MenuChoosePerson("Choose person")).process())
        );
        return true;
    }

    /**
     * @param item
     * @return
     */
    protected Object onCreateContractTenancy(Object item) {
        (new EntityManager()).persist(
                (new Tenancy()).setContract_no(FormUtil.readInt("Contract No"))
                        .setPlace(FormUtil.readString("Place"))
                        .setDate(FormUtil.readDate("Date ('MMMM d, yyyy')"))
                        .setDuration(FormUtil.readInt("Duration"))
                        .setAdditional_costs(FormUtil.readFloat("Duration"))
                        .setStart(FormUtil.readDate("Start date ('MMMM d, yyyy')"))
                        .setEstate((new MenuChooseApartment("Choose apartment")).process())
                        .setPerson((new MenuChoosePerson("Choose person")).process())
        );

        return true;
    }

}
