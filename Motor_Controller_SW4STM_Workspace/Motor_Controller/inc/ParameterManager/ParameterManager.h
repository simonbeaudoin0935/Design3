#ifndef PARAMETERMANAGER_H_
#define PARAMETERMANAGER_H_




class ParameterManager {
public:
	ParameterManager();
	virtual ~ParameterManager();

	static ParameterManager* getManager();

	void initEeprom();
	void loadParametersFromEEPROM();
	void storeParametersInEEPROM();
	struct{
		float m_motor_1_PKp;
		float m_motor_1_PKi;
		float m_motor_1_PKd;
		float m_motor_1_VKp;
		float m_motor_1_VKi;
		float m_motor_1_VKd;
		float m_motor_1_Amax;
		float m_motor_1_Vmax;

		float m_motor_2_PKp;
		float m_motor_2_PKi;
		float m_motor_2_PKd;
		float m_motor_2_VKp;
		float m_motor_2_VKi;
		float m_motor_2_VKd;
		float m_motor_2_Amax;
		float m_motor_2_Vmax;

		float m_motor_3_PKp;
		float m_motor_3_PKi;
		float m_motor_3_PKd;
		float m_motor_3_VKp;
		float m_motor_3_VKi;
		float m_motor_3_VKd;
		float m_motor_3_Amax;
		float m_motor_3_Vmax;

		float m_motor_4_PKp;
		float m_motor_4_PKi;
		float m_motor_4_PKd;
		float m_motor_4_VKp;
		float m_motor_4_VKi;
		float m_motor_4_VKd;
		float m_motor_4_Amax;
		float m_motor_4_Vmax;

		float m_wheel_diameter;
		float m_dt;

	}m_parameters;

private:

	static ParameterManager* m_parameterManagerPtr;
};

#endif /* PARAMETERMANAGER_H_ */
