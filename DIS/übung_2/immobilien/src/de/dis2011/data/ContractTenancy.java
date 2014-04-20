package de.dis2011.data;

import java.util.Date;

public class ContractTenancy {
    private int id;
    private Date started_at;
    private Contract contract;
    private Rent rent;
    private float duration;
    private float additional_costs;

    public int getId() {
        return id;
    }


    public void setId(int id) {
        this.id = id;
    }

    public Contract getContract() {
        return this.contract;
    }

    public ContractTenancy setContract(Contract contract) {
        this.contract = contract;
        return this;
    }

    public Rent getRent() {
        return this.rent;
    }

    public ContractTenancy setRent(Rent rent) {
        this.rent = rent;
        return this;
    }

    public Date getStartedAt() {
        return this.started_at;
    }

    public ContractTenancy setStartedAt(Date startedAt) {
        this.started_at = startedAt;
        return this;
    }

    public float getDuration() {
        return this.duration;
    }

    public ContractTenancy setDuration(float duration) {
        this.duration = duration;
        return this;
    }

    public float getAdditionalCosts() {
        return this.additional_costs;
    }

    public ContractTenancy setAdditionalCost(float additionalCost) {
        this.additional_costs = additionalCost;
        return this;
    }

    /**
     * Convert object to string
     *
     * @return
     */
    public String toString() {

        return new String(
                "\n\t Started: " +
                        this.getStartedAt() +
                        "\n\t Rent: \n\t" +
                        this.getRent() +
                        "\n\t Contract: \n\t" +
                        this.getContract() +
                        "\n\t Duration: " +
                        this.getDuration() +
                        "\n\t Additional cost: " +
                        this.getAdditionalCosts()
        );
    }

}
