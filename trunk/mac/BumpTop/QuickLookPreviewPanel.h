/*
 *  Copyright 2012 Google Inc. All Rights Reserved.
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *      http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef BUMPTOP_QUICKLOOKPREVIEWPANEL_H_
#define BUMPTOP_QUICKLOOKPREVIEWPANEL_H_

#include "BumpTop/VisualPhysicsActor.h"

class QuickLookInterface;
class Room;

class QuickLookPreviewPanel : public QObject {
  Q_OBJECT
 public:
  explicit QuickLookPreviewPanel(Room* room);
  ~QuickLookPreviewPanel();

  void toggle();

 protected slots:  // NOLINT
  void selectedActorsChanged();
  void renderTick();

 protected:
  QHash<QString, VisualPhysicsActorId> getRoomSelectedActorPaths();
  void previewPanelNeedsUpdating();

  Room* room_;
  QuickLookInterface* quick_look_interface_;
  bool preview_panel_needs_updating_;
};

#endif  // BUMPTOP_QUICKLOOKPREVIEWPANEL_H_
