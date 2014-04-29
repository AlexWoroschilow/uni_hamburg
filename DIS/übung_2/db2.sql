ALTER TABLE uebung2.estate_agent
  CONSTRAINT fk_estate_agent_estate1
    FOREIGN KEY (estate_id)
    REFERENCES uebung2.estate (id)
    ON DELETE NO CASCADE
    ON UPDATE NO CASCADE)
