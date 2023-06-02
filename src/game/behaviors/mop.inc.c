extern void bounce_off_object(struct MarioState *m, struct Object *obj, f32 velY);

void bhv_move_rotate_init(void) {
	o->oTimer += 0x40 * o->oBehParams2ndByte;
	o->oAnimState = o->oBehParams2ndByte;
}

#define PLAT_SPEED 8

void bhv_move_rotate_loop(void) 
{
	if (o->oTimer == 0x60)
    {
		o->oAngleVelPitch += 0x400;
	}
    else if (o->oTimer == 0x80)
    {
		o->oAngleVelPitch = 0;
		o->oTimer = 0;
	}
	cur_obj_rotate_face_angle_using_vel();
}

//0 reg, 1 reset
void bhv_checkpoint_flag_loop(void) 
{
    o->oIntangibleTimer = 0;
    if (o->oDistanceToMario < 150.0f || (gMarioStates[0].interactObj == o))
    {
        if (o->oAction == 0)
        {
            o->oAction = 1;
        }
    }
    else
    {
        // -
    }
}

#define SHRINK_TIME 150
#define SHRINK_TIMEF 150.0f

void bhv_shrinkplatform_loop(void)
{
	if (o->oAction < 2)
    {
        load_object_collision_model();
	}
	//disappearing
	switch(o->oAction)
    {
		case 0:
			o->header.gfx.scale[0] = 1.3f;
			o->header.gfx.scale[2] = 1.3f;
			break;
		case 1:
			if (o->oTimer == SHRINK_TIME)
            {
				o->activeFlags = 0;
				// o->oAction = 2;
				return;
			}
			o->header.gfx.scale[0] = 1.3f * ((f32)(SHRINK_TIME-o->oTimer)) / SHRINK_TIMEF;
			o->header.gfx.scale[2] = 1.3f * ((f32)(SHRINK_TIME-o->oTimer)) / SHRINK_TIMEF;
			break;
		case 2:
			cur_obj_hide();
			if (o->oTimer == (SHRINK_TIME+1))
            {
				o->oAction = 0;
				o->header.gfx.scale[0] = 1.3f;
				o->header.gfx.scale[2] = 1.3f;
				cur_obj_unhide();
			}
			break;
	}
	if (cur_obj_is_mario_on_platform() && o->oAction == 0)
    {
		o->oAction = 1;
		cur_obj_play_sound_1(SOUND_OBJ_UNK23);
	}
}

void bhv_Spring_loop(void)
{
	f32 Yspd = 56.0f;
	u32 CarmackMeme;
	u32 Tmp;
	if (o->oAction == 0)
    {
		if (obj_check_if_collided_with_object(o, gMarioObject))
        {
			set_mario_action(gMarioState, ACT_FREEFALL, 0);
			gMarioStates[0].faceAngle[1] = o->oFaceAngleYaw;
			CarmackMeme = *(u32*) &Yspd;
			Tmp = CarmackMeme;
			gMarioStates[0].forwardVel = *(f32*) &Tmp;
			bounce_off_object(gMarioState, o, *(f32*) &CarmackMeme);
			gMarioStates[0].vel[1] = *(f32*) &CarmackMeme; //?? Redundant but somehow necessary??
			o->oAction = 1;
		}
	}
    else
    {
		if (o->oTimer == 15)
        {
			o->oAction=0;
		}
	}
}

void bhv_noteblock_loop(void)
{
	f32 Yspd = 80.0f;
	u32 CarmackMeme;
	if (cur_obj_is_mario_on_platform())
    {
		if (gMarioStates[0].action != ACT_DIVE && (gMarioStates[0].controller->buttonPressed & A_BUTTON))
        {
			Yspd = 200;
		}
		set_mario_action(gMarioState, ACT_DOUBLE_JUMP, 0);
		CarmackMeme = * (u32 *) &Yspd;
		Yspd = *(f32 *) &CarmackMeme;
		gMarioStates[0].vel[1] = Yspd;
		o->oAction = 1;
	}

    if (o->oAction == 1)
    {
		if (o->oTimer == 4)
        {
			o->oAction = 0;
			o->oPosY = o->oHomeY;
		}
        else
        {
			if (o->oTimer>2)
            {
				o->oPosY = o->oHomeY + (o->oTimer % 3) * 6;
			}
            else
            {
				o->oPosY = o->oHomeY - o->oTimer * 6;
			}
		}
	}
}

void bhv_sandblock_loop(void) {
	if (o->oAction < 2)
    {
		load_object_collision_model();
	}
	//disappearing
	switch(o->oAction)
    {
		case 1:
			if (o->oTimer == 300)
            {
				o->activeFlags = 0;
				o->oAction = 2;
				return;
			}
			o->header.gfx.scale[1] = ((f32)(300-o->oTimer))/300.0f;
			spawn_object_relative(0, 0, 0, 0, o, 0, bhvDirtParticleSpawner);
			cur_obj_play_sound_1(SOUND_ENV_MOVINGSAND);
			break;
		case 2:
			cur_obj_hide();
			if (o->oTimer == 301)
            {
				o->oAction = 0;
				o->header.gfx.scale[1] = 1.0f;
				cur_obj_unhide();
			}
			break;
	}
	if (cur_obj_is_mario_on_platform() && o->oAction==0){
		o->oAction = 1;
	}
}