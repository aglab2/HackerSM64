void bhv_sticky_plat_loop(void){
	f32 spd = (f32) ((o->oBehParams) & 0xFF) * 2.0f;
	if(o->oTimer >= 31){
		++o->oAction;
	}
	switch(o->oBehParams2ndByte){
		case 0:
			if(o->oAction%2 == 0){
				o->oVelY = spd;
			}else{
				o->oVelY = 0;
			}
			if(o->oAction%4 == 2){
				o->oVelY = -spd;
			}
			break;
		case 1:
			if(o->oAction%2 == 0){
				o->oFaceAngleYaw += 1024;
				o->oAngleVelYaw = 1024;
			}else{
				o->oAngleVelYaw = 0;
			}
			break;
		case 2:
			o->oFaceAngleYaw += 512;
			o->oAngleVelYaw = 512;
			break;
	}
}

void bhv_hanging_plat_init(void){
	o->oMoveAngleYaw = o->oFaceAngleYaw;
}

void bhv_hanging_plat_init2(void)
{
	if (1 == o->oBehParams2ndByte)
	{
		{
			struct Object* other = spawn_object(o, MODEL_HANGING_PLAT, bhvHangingPlat);
			other->oBehParams2ndByte = o->oBehParams2ndByte;
			other->oBehParams = o->oBehParams;
			other->oAction = 2;
			f32 spd = (f32) ((o->oBehParams) & 0xFF) * 2.0f;
			other->oPosX = o->oPosX + spd * 48;
			other->oPosY = o->oPosY;
			other->oPosZ = o->oPosZ + spd * 48;
			other->oBehParams2ndByte = 3;
		}
		{
			struct Object* other = spawn_object(o, MODEL_HANGING_PLAT, bhvHangingPlat);
			other->oBehParams2ndByte = o->oBehParams2ndByte;
			other->oBehParams = o->oBehParams;
			other->oAction = 1;
			f32 spd = (f32) ((o->oBehParams) & 0xFF) * 2.0f;
			other->oPosX = o->oPosX;
			other->oPosY = o->oPosY;
			other->oPosZ = o->oPosZ + spd * 48;
			other->oBehParams2ndByte = 3;
		}
		{
			struct Object* other = spawn_object(o, MODEL_HANGING_PLAT, bhvHangingPlat);
			other->oBehParams2ndByte = o->oBehParams2ndByte;
			other->oBehParams = o->oBehParams;
			other->oAction = 3;
			f32 spd = (f32) ((o->oBehParams) & 0xFF) * 2.0f;
			other->oPosX = o->oPosX + spd * 48;
			other->oPosY = o->oPosY;
			other->oPosZ = o->oPosZ;
			other->oBehParams2ndByte = 3;
		}
	}
}

void bhv_hanging_plat_loop(void){
	f32 spd = (f32) ((o->oBehParams) & 0xFF) * 2.0f;
	u8 time = ((o->oBehParams>>24) & 0xFF) / 2.0f;
	if(time == 0){
		time = 60;
	}
	if(o->oTimer > time){
		++o->oAction;
	}
	switch(o->oBehParams2ndByte){
		case 0:
			if(o->oAction%2 == 0){
				o->oVelY = spd;
			}else{
				o->oVelY = 0;
			}
			if(o->oAction%4 == 2){
				o->oVelY = -spd;
			}
			break;
		case 1:
		case 3:
			if(o->oTimer<12){
				o->oForwardVel = 0.0f;
			}else{
				o->oForwardVel = spd;
			}
			o->oMoveAngleYaw = o->oAction * 0x4000;
			break;
		case 2:
			o->oForwardVel = spd;
			o->oMoveAngleYaw += 0x100;
			break;
	}
}


void bhv_floating_plat_init(void){
	o->parentObj = cur_obj_find_nearest_object_with_behavior_and_bparam(bhvFloatingPlatSwitch, (o->oBehParams&0xFF));
}

void bhv_floating_plat_loop(void){
	f32 delta = (o->oBehParams >> 16 & 0xFF)*10.0f;
	if(o->parentObj){
		switch(o->oAction){
			case 0:
				o->oOpacity = 0;
				if(o->parentObj->oAction > 0 && o->parentObj->oAction < 3){
					o->oAction = 1;
				}
				break;
			case 1:
				if(o->oPosY-o->oHomeY < delta){
					if (o->oVelY >= delta/20.0f) {
						o->oVelY = delta/20.0f;
					} else {
						o->oVelY += delta / 1024.0f;
					}
					o->oPosY += o->oVelY;
				}else{
					o->oPosY = o->oHomeY + delta;
				}
				o->oOpacity += 3;
				if(o->oOpacity >= 0xF0){
					o->oAction = 2;
					o->oOpacity = 0xF0;
					o->oVelY = 0;
				}
				
				break;
			case 2:
				if(o->parentObj->oAction>2){
					o->oAction = 3;
				}
				break;
			case 3:
				if(o->oPosY > o->oHomeY){
					if (o->oVelY >= delta/20.0f) {
						o->oVelY = delta/20.0f;
					} else {
						o->oVelY += delta / 1024.0f;
					}
					o->oPosY -= o->oVelY;
				}else{
					o->oPosY = o->oHomeY;
				}
				o->oOpacity -= 3;
				if(o->oOpacity <= 4){
					o->oAction = 0;
					o->oOpacity = 0;
					o->oVelY = 0;
				}
				break;
		}
	}
	//add squish protection since this is something that can fall
	if(gMarioState->action == ACT_SQUISHED && gMarioState->ceil){
		//idk if you can be squished without a ceiling but I'm not gonna bother testing
		if(gMarioState->ceil->object == o){
			o->oHealth = 1;
		}
	}
	//wait until mario is radius R away and above object before becoming solid again
	if(o->oHealth){
		if(o->oDistanceToMario > 250.0f || gMarioState->pos[1] > (o->oPosY-50.0f)){
			o->oHealth = 0;
		}
	}else{
		load_object_collision_model();
	}
	
}


