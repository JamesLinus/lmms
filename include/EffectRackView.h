/*
 * effect_rack_view.h - view for effectChain-model
 *
 * Copyright (c) 2006-2007 Danny McRae <khjklujn@netscape.net>
 * Copyright (c) 2008 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 *
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#ifndef _EFFECT_RACK_VIEW_H
#define _EFFECT_RACK_VIEW_H

#include <QtGui/QWidget>

#include "EffectChain.h"
#include "ModelView.h"
#include "lmms_basics.h"

class QScrollArea;
class QVBoxLayout;

class EffectView;
class groupBox;


class EffectRackView : public QWidget, public ModelView
{
	Q_OBJECT
public:
	EffectRackView( EffectChain * _model, QWidget * _parent = NULL );
	virtual ~EffectRackView();

	QVBoxLayout * mainLayout()
	{
		return m_mainLayout;
	}


public slots:
	void clearViews();
	void moveUp( EffectView * _view );
	void moveDown( EffectView * _view );
	void deletePlugin( EffectView * _view );


private slots:
	virtual void update();
	void addEffect();


private:
	virtual void modelChanged();

	inline EffectChain * fxChain()
	{
		return castModel<EffectChain>();
	}

	inline const EffectChain * fxChain() const
	{
		return castModel<EffectChain>();
	}


	QVector<EffectView *> m_effectViews;

	QVBoxLayout * m_mainLayout;
	groupBox * m_effectsGroupBox;
	QScrollArea * m_scrollArea;

	Uint32 m_lastY;

} ;

#endif