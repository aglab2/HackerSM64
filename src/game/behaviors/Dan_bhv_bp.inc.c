
void Dan_bhv_bp_loop(void) {
	enum {
		BP_ACT_INIT,
		BP_ACT_LOOP,
		BP_ACT_START,
	};

	s32 puff = TRUE;
	while (puff) {
		struct Object *p = cur_obj_nearest_object_with_behavior(bhvWhitePuff1);
		if (p != NULL) {
			p->activeFlags = 0; }
		else {
			puff = FALSE; }
	}			
	puff = TRUE;
	while (puff) {
		struct Object *p = cur_obj_nearest_object_with_behavior(bhvWhitePuff2);
		if (p != NULL) {
			p->activeFlags = 0; }
		else {
			puff = FALSE; }
	}


	switch (o->oAction) {
	case BP_ACT_INIT:
		gMarioObject->collidedObjs[1] = spawn_object(o, MODEL_LEVEL_GEOMETRY_05, bhvStaticObject);
		struct Object *c = spawn_object(o, 0, bhvIgloo);
		c->hitboxHeight = 50.f;
		c->hitboxRadius = 50.f;
		c = cur_obj_nearest_object_with_behavior(bhvStar);
		c->oFlags |= OBJ_FLAG_ACTIVE_FROM_AFAR;
		o->oAction = BP_ACT_LOOP;
		break;


	case BP_ACT_LOOP:
		if (dist_between_objects(gMarioObject, o) < 150.f) {
			if ((gMarioState->action == ACT_WALKING) || (gMarioState->action & ACT_FLAG_AIR)) {
				gHudDisplay.flags = 0;

				gCamera->cutscene = CUTSCENE_SSL_PYRAMID_EXPLODE;

				gMarioState->pos[0] = o->oPosX;
				gMarioState->pos[1] = o->oPosY + 10.f;
				gMarioState->pos[2] = o->oPosZ;
				gMarioState->faceAngle[0] = 0;
				gMarioState->faceAngle[1] = -(DEGREES(90));

				vec3f_copy(gMarioObject->header.gfx.pos, gMarioState->pos);
				vec3s_copy(gMarioObject->header.gfx.angle, gMarioState->faceAngle);
				gMarioState->marioBodyState->torsoAngle[2] = 0;
				gMarioState->marioBodyState->torsoAngle[0] = 0;

				o->header.gfx.scale[1] = 0.1f;
				play_peachs_jingle();

				set_mario_action(gMarioState, ACT_BACKWARD_AIR_KB, 0);
				set_mario_animation(gMarioState, MARIO_ANIM_CREDITS_START_WALK_LOOK_UP);
				o->oAction++;
			}
		} else {
			if (!gCurrCreditsEntry && (gPlayer1Controller->buttonDown & A_BUTTON) && (gPlayer1Controller->buttonDown & B_BUTTON) && (gPlayer1Controller->buttonDown & Z_TRIG)) {
				if (o->oTimer > 90) {
					gMarioState->pos[0] = -21400;
					gMarioState->pos[1] = 1200;
					gMarioState->pos[2] = -1300;
					o->oAction = 50;
				}
			} else {
				o->oTimer = 0; }
		}
		break;


	case BP_ACT_START:
		o->oPosX -= 0.5f;
		o->oFaceAngleYaw += 15;
		if (o->oTimer > (30 * 12)) {
			o->oAction++; }
		break;

	case 50:
		print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y, "CUTSCENE SKIPPED");
		print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y - 60, "THIS RUN BETTER BE GOOD");
		if (o->oTimer > 45) {
			o->activeFlags = 0; }
	}
}
